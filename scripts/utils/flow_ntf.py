#!/usr/bin/env python3
#coding=utf-8
#########################################################################
# Author: @maris
# Created Time: May 18  2017 18:55:41 PM CST
# File Name:my_token.py
# Description:封装flow cli, test nft
# SPDX-License-Identifier: MIT
#########################################################################
import sys
import re
import json
import time
import io
import os
#from subprocess import Popen, PIPE
import flow_account


config = "flow.json"
#附属参数
PARAM = " -o json -n testnet -f {} --signer testnet-account ".format(config)

def test():
    com = "flow status {}".format(PARAM)
    val = os.popen(com)
    print(val.read())


"""
功能：生成nft
输入：address, sent nft to this address
输入：data, dict格式数据
返回：nft的id
"""
def create_nft(address, data):
    com = "flow transactions send mint_nft_item.cdc {} '{}' {}".format(address, json.dumps(data, ensure_ascii=False), PARAM)
    val = os.popen(com)
    result = val.read().strip()
    data = json.loads(result)
    #print(data)
    #step 3, get item id
    nft_id = -1
    for item in data["events"]:
        event_type = item["type"]
        if -1!=event_type.find("Nftly.Minted"):
            nft_id = item["values"]["value"]["fields"][0]["value"]["value"]

    trans_id = data["id"]
    return trans_id, nft_id

"""
功能：create user nft vault
输入：address， user address
返回：transaction_id
"""
def create_user_nft_vault(address):
    # step 1,  user address in flow.josn
    user_name = "user_" + address.replace("0x", "")

    # step 2, create user nft vault
    com = 'flow transactions send ../trans/setup_nft_account.cdc -n testnet  -o json --signer {}'.format(user_name)
    val = os.popen(com)
    result = val.read().strip()
    data = json.loads(result)
    #print(data)
    #step 3, get transaction id
    trans_id = data["id"]
    return trans_id


"""
功能：给用户发送nft
输入：address， 用户地址
输入：nft_id，nft的id
返回：transaction_id，交易地址
"""
def send_user_nft(address, nft_id):
    com = "flow transactions send ../trans/transfer_nft_item.cdc {} {} {}".format(address, nft_id, PARAM)
    val = os.popen(com)
    result = val.read().strip()
    data = json.loads(result)
    #print(data)
    trans_id = data["id"]
    return trans_id

"""
功能：cadence format to json
input: data, cadence data format
return: json format data
"""
def convert(data):
    data_new = {}
    for item in data["value"]:
        key = item["key"]["value"]
        value = item["value"]["value"]
        data_new[key] = value
    return data_new

"""
功能：获得nft的metadata
输入：address, user address
输入：nft_id，nft的id
返回：metadata
"""
def get_nft_metadata(address, nft_id):
    com = 'flow scripts execute ../script/get_nft_metadata.cdc {} {} -n testnet -o json'.format(address, nft_id)
    #print(com)
    val = os.popen(com)
    result = val.read().strip()
    data = json.loads(result)
    return convert(data)

"""
功能：获得用户nft
输入：address， 用户地址
返回：用户nft id列表
"""
def get_user_nft_list(address):
    com = 'flow scripts execute ../script/get_collection_ids.cdc {} -o json -n testnet'.format(address)
    #print(com)
    val = os.popen(com)
    result = val.read().strip()
    data = json.loads(result)
    #print(data)

    id_list = []
    for item in data["value"]:
        nft_id = int(item["value"])
        id_list.append(nft_id)

    return id_list


if __name__=="__main__":
    admin_address = "0x5e1e16ea71ac90c2"
    #user_address = "0xc82fef614497fd3e"

    # #step 0, create new user
    # private_key, public_key, address, transaction_id = flow_account.ini_new_user_account()
    # user_address = "0x" + address
    # print("0. create new flow user", user_address)
    #
    # #step 1, initial user nft vault
    # trans_id = create_user_nft_vault(user_address)
    # print("1. initial user nft vault success, trans id", trans_id)

    #step 2, create a nft, for admin
    metadata = {"name":"imagenet_101", "cid":"/ipfs/QmZMgMg36P5TTePoyLNUJyukrd2Y93DUqp5PZphu3yLva3/n00017222/n00017222_1012.JPEG"}
    trans_id, nft_id = create_nft(admin_address, metadata)
    print("2. create new nft, nft id is ", nft_id, " ,transaction id is ", trans_id)

    # #step 3, send nft to user
    # trans_id = send_user_nft(user_address, nft_id)
    # print("3. transfer nft to user success, nft id:", nft_id, "trans id", trans_id)
    #
    # # #step 4, get user nft ids
    # nft_id_list = get_user_nft_list(user_address)
    # print("4. nft id list of user", nft_id_list)
    #
    # #step 5, get metadata
    # metadata = get_nft_metadata(user_address, nft_id_list[0])
    # # metadata = get_nft_metadata(user_address, 4)
    # print("5. nft id:",  nft_id_list[0], "metdata data is:", metadata)

