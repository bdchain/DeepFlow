import os
import sys
import time

import json
import csv
import argparse

import tqdm
from subprocess import Popen, PIPE

from utils.flow_account import get_key, create_account

config = "flow.json"
PARAM = " -n testnet -f {} --signer testnet-account ".format(config)

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--create_account", required=False,
                        help="Fetch block with a new account instead of an existing one.")
    parser.add_argument("-n", "--network", default="testnet",
                        help="Target network.")


def get_block(block_height):
    try:
        cmd = f"flow blocks get {block_height} -n mainnet"
        val = os.popen(cmd)
        item = val.read()
        
        # Remove irrelevant content
        item = item[item.find("Block ID"):]
        data = item.split('\n')

        # Parse data
        block_id = data[0].split('\t')[-1]
        parent_id = data[1].split('\t')[-1]
        raw_time = data[2].split('\t')[-1]
        height = data[3].split('\t')[-1]
        total_seals = data[4].split('\t')[-1]
        collection_cnt = int(data[5].split('\t')[-1])
        collections = []
        for i in range(collection_cnt):
            collections.append(data[6+i].split('\t')[-1])

        # Get timestamp
        time_s = raw_time[:raw_time.find("+")-1]
        dot_index = time_s.find(".")
        timestamp = -1.
        if dot_index < 0:
            ftime = time.strptime(time_s, "%Y-%m-%d %H:%M:%S")
            timestamp = time.mktime(ftime)
        else:
            fraction = float(time_s[dot_index:])
            ftime = time.strptime(time_s[:dot_index], "%Y-%m-%d %H:%M:%S")
            timestamp = time.mktime(ftime) + fraction
    except:
        print("Get block Error: \n" + item)
        
    ret = [block_id, parent_id, timestamp, height, total_seals, collection_cnt]
    return ret + collections



if __name__ == "__main__":
    csv_file = open("Blocks.csv", 'a', newline="")
    writer = csv.writer(csv_file)
    # writer.writerow(
    #     ["block_id", "parent_id", "timestamp", "height", "total_seals", "collection_cnt", "collections"])
    for height in range(21835621, 23830812):
        item_row = get_block(height)
        writer.writerow(item_row)

    csv_file.close()
