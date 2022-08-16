import os
import sys
sys.path.append("/data/charles/deep_flow/rpc")
sys.path.append(os.getcwd())
import json
from sql.flow_sql import *
from sql.sql_utils import *

import asyncio
from html import entities
import flow_py_sdk
from flow_py_sdk import flow_client


# create table
table_name = "flow_token_transfer"
if has_table(table_name):
    sql_utils.mysql_com(f"truncate `{table_name}`;")
else:
    sql_utils.mysql_com(
        f"CREATE TABLE `{table_name}`  ("
        r"    `id` int UNSIGNED NOT NULL AUTO_INCREMENT,"
        r"    `height` int UNSIGNED NOT NULL,"
        r"    `tx_id` char(64) NOT NULL,"
        r"    `proposer` char(16) NOT NULL,"
        r"    `send` json NOT NULL,"
        r"    `receive` json NOT NULL,"
        r"    PRIMARY KEY (`id`),"
        r"    UNIQUE INDEX `uniq_tx_id`(`tx_id`)"
        r");"
    )

# data in [6.12, 6.19)
block_range = (31488850, 32488850)
# table_idx = {17: [82, 83, 84, 85, 86, 87], 18: [0, 1]}
table_idx = {18: [0]}

for spork in table_idx:
    for division in table_idx[spork]:
        block_table = f"blocks_{spork}_{division}"
        col_table = f"collections_{spork}_{division}"
        tx_table = f"transactions_{spork}_{division}"
        event_table = f"events_{spork}_{division}"
        print(f"Start to traverse block table {block_table}")

        block_entries = sql_utils.mysql_com(
            f"select height,collections from {block_table} where height>={block_range[0]} and height<={block_range[1]};"
        )
        for block_entry in block_entries:
            height = block_entry["height"]
            cols_raw = block_entry["collections"]
            guarantees = json.loads(cols_raw)["collection_guarantees"]
            for guarantee in guarantees:
                col_id = guarantee["collection_id"]
                col_entries = sql_utils.mysql_com(
                    f"select tx_ids from {col_table} where collection_id='{col_id}';"
                )
                assert len(col_entries) == 1
                tx_ids = json.loads(col_entries[0]["tx_ids"])["transaction_ids"]
                for tx_id in tx_ids:
                    tx_entries = sql_utils.mysql_com(
                        f"select proposal_key,status_code from {tx_table} where tx_id='{tx_id}';"
                    )
                    assert len(tx_entries) == 1
                    status_code = tx_entries[0]["status_code"]
                    if status_code != 0:
                        continue
                    proposal_key_raw = tx_entries[0]["proposal_key"]
                    proposer = json.loads(proposal_key_raw)["address"]
                    event_entries = sql_utils.mysql_com(
                        f"select payload from {event_table} where tx_id='{tx_id}'"
                    )
                    send = {}
                    receive = {}
                    for event_entry in event_entries:
                        payload_raw = event_entry["payload"]
                        payload = json.loads(payload_raw)["value"]
                        etype = payload["id"]
                        fields = payload["fields"]
                        if etype == "A.1654653399040a61.FlowToken.TokensDeposited":
                            assert fields[0]["name"] == "amount" and fields[1]["name"] == "to"
                            amount = float(fields[0]['value']['value'])
                            if fields[1]["value"]["value"] is None:
                                continue
                            addr = fields[1]['value']['value']['value']
                            if addr in receive:
                                receive[addr] += amount
                            else:
                                receive[addr] = amount
                        elif etype == "A.1654653399040a61.FlowToken.TokensWithdrawn":
                            assert fields[0]["name"] == "amount" and fields[1]["name"] == "from"
                            amount = float(fields[0]["value"]["value"])
                            if fields[1]["value"]["value"] is None:
                                continue
                            addr = fields[1]["value"]["value"]["value"]
                            if addr in send:
                                send[addr] += amount
                            else:
                                send[addr] = amount
                    
                    entry = {}
                    entry["height"] = height
                    entry["tx_id"] = tx_id
                    entry["proposer"] = proposer
                    entry["send"] = json.dumps(send)
                    entry["receive"] = json.dumps(receive)
                    sql_utils.insert_data(entry, table_name)

                    

