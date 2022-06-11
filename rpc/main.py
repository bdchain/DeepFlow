from os import access
import sys
import queue
import time
import asyncio
import threading
from html import entities
import flow_py_sdk
from flow_py_sdk import flow_client
from sql.flow_sql import *
from utils import *
from flow_grabber import Grabber



if __name__ == "__main__":
    mainnet_idx = int(sys.argv[1])
    sporks = parse_spork_from_file()

    # truncate_all_tables()
    # create_all_tables()
    # drop_all_tables()

    start_height = sporks[mainnet_idx][0]
    end_height = sporks[mainnet_idx+1][0]
    access_node = sporks[mainnet_idx][1]
    grabber = Grabber(mainnet_idx, start_height, end_height, access_node)
    grabber.coroutine_num = 12
    grabber.run()
