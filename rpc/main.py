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

is_fetching: bool = True
insert_q = queue.Queue()

async def test():
    async with flow_client(
            host="access.mainnet.nodes.onflow.org", port=9000
    ) as client:

        transaction_id = bytes.fromhex("b0b6765eff4bc4960f01fdd6521a2e7f7a4847ba4a771fd1f678cc4eb831414f")
        transaction = await client.get_transaction(id=transaction_id)
        print("transaction ID: {}".format(transaction_id.hex()))
        print("transaction payer: {}".format(transaction.payer.hex()))
        print("transaction authorizers: {}".format(transaction.authorizers))
        print("transaction proposal_key: {}".format(transaction.proposal_key))

        print("transaction proposer: {}".format(
                transaction.proposal_key.address.hex()
            )
        )

        print("transaction arguments: {}".format(transaction.arguments))


        print("transaction script: {}".format(transaction.script.decode("utf-8")))


async def retrieve_block_from_latest(root_height: int):
    global is_fetching

    async with flow_client(
        host="access.mainnet.nodes.onflow.org", port=9000
    ) as client:

        latest_block = await client.get_latest_block()
        latest_height = latest_block.height - 100


        print(f"Start fetching block data from height {latest_height}")
        print(f"Target height(root height): {root_height}", flush=True)
        MAX_TRIAL_CNT = 3
        for height in range(latest_height, root_height-1, -1):
            block = await client.get_block_by_height(height=height)
            SQL_CHECK(insert_block(block))
            col_guarantees = block.collection_guarantees
            tx_ids = []
            for j in range(len(col_guarantees)):
                collection_id = col_guarantees[j].collection_id
                collection = await client.get_collection_by_i_d(id=collection_id)
                SQL_CHECK(insert_collection(collection))
                tx_ids += collection.transaction_ids
            for tx_id in tx_ids:
                tx = await client.get_transaction(id=tx_id)
                tx_result = await client.get_transaction_result(id=tx_id)
                SQL_CHECK(insert_transaction(tx, tx_result, tx_id))
                # for event in tx_result.events:
                #     SQL_CHECK(insert_event(event))
                SQL_CHECK(insert_events(tx_result.events))
            
            if height % 1000 == 0:
                print(f"Block {height} fetched and processed!", flush=True)

        print(f"All blocks fetched successfully!", flush=True)
        is_fetching = False

                
async def retrieve_block_by_range(start_height: int, end_height: int, access_node: str):
    global insert_q
    access_host, access_port = access_node.split(':')
    access_port = int(access_port)
    async with flow_client(
        host=access_host, port=access_port
    ) as client:

        print(f"Start fetching {end_height - start_height} blocks "
                f"in height range ({start_height}, {end_height})", flush=True)
        for height in range(start_height, end_height):
            block_set = BlockSet()
            block = await client.get_block_by_height(height=height)
            block_set.block = block
            col_guarantees = block.collection_guarantees
            tx_ids = []
            for j in range(len(col_guarantees)):
                collection_id = col_guarantees[j].collection_id
                collection = await client.get_collection_by_i_d(id=collection_id)
                block_set.collections.append(collection)
                tx_ids += collection.transaction_ids

            block_set.tx_ids = tx_ids
            for tx_id in tx_ids:
                tx = await client.get_transaction(id=tx_id)
                block_set.txs.append(tx)
                tx_result = await client.get_transaction_result(id=tx_id)
                block_set.tx_results.append(tx_result)
                block_set.events += tx_result.events
            
            insert_q.put(block_set)
            if height % 1000 == 0:
                print(f"Block {height} fetched and processed!", flush=True)


def insert_block_set(block_set: BlockSet):
    SQL_CHECK(insert_block(block_set.block))
    SQL_CHECK(insert_collections(block_set.collections))
    # SQL_CHECK(insert_transactions(block_set.txs, block_set.tx_results, block_set.tx_ids))
    assert len(block_set.tx_ids) == len(block_set.txs) \
            and len(block_set.txs) == len(block_set.tx_results)
    for i in range(len(block_set.txs)):
        SQL_CHECK(
            insert_transaction(
                block_set.txs[i],
                block_set.tx_results[i],
                block_set.tx_ids[i]
            )
        )
    SQL_CHECK(insert_events(block_set.events))


def insert_data_loop():
    global is_fetching
    global insert_q
    print(f"Start thread to insert block data into database.")
    while is_fetching:
        if insert_q.empty():
            time.sleep(0.1)
        else:
            block_set: BlockSet = insert_q.get()
            insert_block_set(block_set)
    while not insert_q.empty():
        block_set: BlockSet = insert_q.get()
        insert_block_set(block_set)
    print(f"Inserting loop finished!")


if __name__ == "__main__":
    mainnet_idx = int(sys.argv[1])
    sporks = parse_spork_from_file()

    t_insert = threading.Thread(target=insert_data_loop)
    t_insert.start()
    asyncio.run(
        retrieve_block_by_range(
            sporks[mainnet_idx][0], 
            sporks[mainnet_idx+1][0], 
            sporks[mainnet_idx][1]
        )
    )
    t_insert.join()
    
    # asyncio.run(retrieve_block_from_latest(sporks[-1][0]))

    # truncate_all_tables()