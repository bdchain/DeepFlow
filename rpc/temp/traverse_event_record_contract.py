import os
import sys
# sys.path.append("/data2/DeepFlow/rpc")
sys.path.append(os.getcwd())
from sql.flow_sql import *
from sql.sql_utils import *

import asyncio
from html import entities
import flow_py_sdk
from flow_py_sdk import flow_client


# async def test():
#     client = flow_client("access.mainnet.nodes.onflow.org", 9000)
#     account = await client.get_account_at_latest_block(address=bytes.fromhex("ecfad18ba9582d4f"))
#     print(account.address.hex())
#     print(account.balance)
#     print(account.code)
#     for k in account.keys:
#         print(f"key: {k.hex()}")
#     for pair in account.contracts:
#         code = account.contracts[pair].decode("utf-8")
#         print(f"name: {pair}, code: {code}")
# asyncio.run(test())

# create_contract_table()

async def traverse_event_record_contract():
    recorded_addrs = set()

    client = flow_client("access.mainnet.nodes.onflow.org", 9000)
    tables = sql_utils.mysql_com(f"show tables;")
    event_tables = []
    for t in tables:
        table_name = t["Tables_in_flow"]
        if table_name.split('_')[0] == "events":
            event_tables.append(table_name)

    for table_name in event_tables:
        sql_comm = f"select count(*) from {table_name};"
        entry_cnt_ret = sql_utils.mysql_com(sql_comm)
        entry_cnt = list(entry_cnt_ret[0].values())[0]
        print(f"{entry_cnt} events to be scanned in table {table_name}", flush=True)
        for i in range(1, entry_cnt+1, 10000):
            if i + 10000 > entry_cnt:
                sql_comm = f"select id,type from {table_name} where id>={i} and id<={entry_cnt};"
            else:
                sql_comm = f"select id,type from {table_name} where id>={i} and id<{i+10000};"
            etypes = sql_utils.mysql_com(sql_comm)
            for etype in etypes:
                components = etype["type"].split('.')
                if components[0] != "A":
                    continue
                addr = components[1]
                if addr in recorded_addrs:
                    continue
                else:
                    recorded_addrs.add(addr)

                sql_comm = f"select * from contracts where address='{addr}' limit 1;"
                recorded = sql_utils.mysql_com(sql_comm)
                if len(recorded) != 0:
                    continue
                
                while True:
                    try:
                        account = await client.get_account_at_latest_block(address=bytes.fromhex(addr))
                    except Exception as e:
                        print(e)
                        print(f"Get account error, addr: 0x{addr}")
                        client = flow_client("access.mainnet.nodes.onflow.org", 9000)
                    else:
                        break
                assert account.address.hex() == addr
                for contract_name in account.contracts:
                    contract_code = account.contracts[contract_name].decode("utf-8")
                    entry = {}
                    entry["name"] = contract_name
                    entry["address"] = addr
                    entry["code"] = contract_code
                    sql_utils.insert_data(entry, "contracts")
                    print(f"Record contract {contract_name}", flush=True)

asyncio.run(traverse_event_record_contract())


