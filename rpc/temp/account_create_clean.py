import os
import sys
import json
sys.path.append(os.getcwd())
from sql.flow_sql import *
from sql.sql_utils import *


db_ret = sql_utils.mysql_com(
    "select tx_id,payload from events_1 where type=\"flow.AccountCreated\""
)
# print(db_ret[0])

wf = open("account_created_mainnet1.txt", 'w')

for entry in db_ret:
    try:
        tx_id = entry['tx_id']
        payload = entry['payload']
        payload_dic = json.loads(payload)
        e_value = payload_dic["value"]
        assert e_value["id"] == "flow.AccountCreated"
        fields = e_value["fields"]
        assert len(fields) == 1
        addr_created = fields[0]["value"]["value"]
        wf.write(f"{addr_created} {tx_id}\n")

    except Exception as e:
        print(entry)
        print(e)

wf.close()

