import os
import json
from typing import List
from flow_py_sdk.client import entities

class BlockSet():
    def __init__(self):
        self.block: entities.Block = None
        self.collections: List[entities.Collection] = []
        self.tx_ids: List[bytes] = []
        self.txs: List[entities.Transaction] = []
        self.tx_results: List[entities.TransactionResultResponse] = []
        self.events: List[entities.Event] = []
        
        self.custom = None


flow_repo_dir = "flow/"

def parse_spork_from_file():
    json_file = os.path.join(flow_repo_dir, "sporks.json")
    json_str = ""
    with open(json_file, 'r') as rf:
        json_str = rf.read()
    json_root = json.loads(json_str)
    sporks = [(0, "")]
    mainnet_node = json_root["networks"]["mainnet"]
    mainnet_cnt = len(mainnet_node) - 6 # six candidate net
    for net_idx in range(1, mainnet_cnt + 1):
        node = mainnet_node[f"mainnet{net_idx}"]
        root_height = int(node["rootHeight"])
        access_node = ""
        if "accessNodes" in node:
            access_node = node["accessNodes"][0]
        elif "accessNode" in node:
            access_node = node["accessNode"][0]
        sporks.append((root_height, access_node))
    sporks[-1] = (sporks[-1][0], "access.mainnet.nodes.onflow.org:9000")
    sporks.append((35000000, "access.mainnet.nodes.onflow.org:9000"))

    return sporks



if __name__ == "__main__":
    sporks = parse_spork_from_file()
    print(sporks)

