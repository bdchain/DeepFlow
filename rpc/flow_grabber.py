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

# async def retrieve_block_from_latest(root_height: int):
#     global is_fetching

#     async with flow_client(
#         host="access.mainnet.nodes.onflow.org", port=9000
#     ) as client:

#         latest_block = await client.get_latest_block()
#         latest_height = latest_block.height - 100


#         print(f"Start fetching block data from height {latest_height}")
#         print(f"Target height(root height): {root_height}", flush=True)
#         MAX_TRIAL_CNT = 3
#         for height in range(latest_height, root_height-1, -1):
#             block = await client.get_block_by_height(height=height)
#             SQL_CHECK(insert_block(block))
#             col_guarantees = block.collection_guarantees
#             tx_ids = []
#             for j in range(len(col_guarantees)):
#                 collection_id = col_guarantees[j].collection_id
#                 collection = await client.get_collection_by_i_d(id=collection_id)
#                 SQL_CHECK(insert_collection(collection))
#                 tx_ids += collection.transaction_ids
#             for tx_id in tx_ids:
#                 tx = await client.get_transaction(id=tx_id)
#                 tx_result = await client.get_transaction_result(id=tx_id)
#                 SQL_CHECK(insert_transaction(tx, tx_result, tx_id))
#                 # for event in tx_result.events:
#                 #     SQL_CHECK(insert_event(event))
#                 SQL_CHECK(insert_events(tx_result.events))
            
#             if height % 1000 == 0:
#                 print(f"Block {height} fetched and processed!", flush=True)

#         print(f"All blocks fetched successfully!", flush=True)
#         is_fetching = False



# async def retrieve_block_by_range(start_height: int, end_height: int, access_node: str):
#     global insert_q
#     access_host, access_port = access_node.split(':')
#     access_port = int(access_port)
#     async with flow_client(
#         host=access_host, port=access_port
#     ) as client:

#         print(f"Start fetching {end_height - start_height} blocks "
#                 f"in height range ({start_height}, {end_height})", flush=True)
#         for height in range(start_height, end_height):
#             block_set = BlockSet()
#             block = await client.get_block_by_height(height=height)
#             block_set.block = block
#             col_guarantees = block.collection_guarantees
#             tx_ids = []
#             for j in range(len(col_guarantees)):
#                 collection_id = col_guarantees[j].collection_id
#                 collection = await client.get_collection_by_i_d(id=collection_id)
#                 block_set.collections.append(collection)
#                 tx_ids += collection.transaction_ids

#             block_set.tx_ids = tx_ids
#             for tx_id in tx_ids:
#                 tx = await client.get_transaction(id=tx_id)
#                 block_set.txs.append(tx)
#                 tx_result = await client.get_transaction_result(id=tx_id)
#                 block_set.tx_results.append(tx_result)
#                 block_set.events += tx_result.events
            
#             insert_q.put(block_set)
#             if height % 1000 == 0:
#                 print(f"Block {height} fetched and processed!", flush=True)



class Grabber():
    def __init__(
            self,
            mainnet_idx: int,
            start_height: int,
            end_height: int,
            access_node: str,
            max_insert_q_size: int = 1000
        ):
        self.insert_q:     queue.Queue = queue.Queue(max_insert_q_size)
        self.mainnet_idx:  int         = mainnet_idx
        self.start_height: int         = start_height
        self.end_height:   int         = end_height
        self.curr_height:  int         = start_height
        self.access_node:  str         = access_node 
        self.is_fetching:  bool        = False

        self._block_num_per_table: int = 50000
        self._coroutine_num: int = 8

    def set_coroutine_num(self, coroutine_num):
        if coroutine_num < 1:
            print("Coroutin number for grabbing task no less than 1")
            return
        elif coroutine_num > 24:
            print("Using too many coroutine for fetching task is not suggested!")
        self.coroutine_num = coroutine_num
        
    @property
    def coroutine_num(self):
        return self._coroutine_num


    def run(self):
        # start inserting flag first
        self.is_fetching = True
        t_insert = threading.Thread(target=self.__insert_data_loop)
        t_insert.start()

        # task_list = [
        #     self.__retrieve_block_multitask(),
        #     self.__retrieve_block_multitask()
        # ]
        table_range = self.__calc_table_block_range()
        print(f"table range division: {table_range}")
        for i in range(len(table_range) - 1):
            self.__create_tables(i)
            self.curr_height = table_range[i]
            target_height = table_range[i+1]
            task_list = [self.__retrieve_block_multitask(target_height, i) \
                for _ in range(self._coroutine_num)]
            asyncio.run(asyncio.wait(task_list))
            print(f"block division {i} complete.")

        self.is_fetching = False
        t_insert.join()

    
    def __create_tables(self, table_id: int):
        create_block_table      (f"blocks_{self.mainnet_idx}_{table_id}")
        create_collection_table (f"collections_{self.mainnet_idx}_{table_id}")
        create_transaction_table(f"transactions_{self.mainnet_idx}_{table_id}")
        create_event_table      (f"events_{self.mainnet_idx}_{table_id}")


    def __calc_table_block_range(self) -> List[int]:
        if self.start_height >= self.end_height:
            raise ValueError(
                f"Wrong grabbing height range, "
                f"start height: {self.start_height}, "
                f"end height: {self.end_height}!"
            )

        table_range = []
        frontier = self.start_height
        while frontier <= self.end_height:
            table_range.append(frontier)
            frontier += self._block_num_per_table
        table_range.append(self.end_height)

        return table_range
            

    async def __retrieve_block_multitask(self, target_height, table_id):
        access_host, access_port = self.access_node.split(':')
        access_port = int(access_port)
        async with flow_client(
            host=access_host, port=access_port
        ) as client:

            while self.curr_height < target_height:

                height = self.curr_height
                self.curr_height += 1
                block_set = BlockSet()
                block_set.custom = table_id
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
                
                self.insert_q.put(block_set)
                if height % 1000 == 0:
                    print(f"Block {height} fetched and processed!", flush=True)

            print(f"One block retrieving coroutine accomplished!")


    def __insert_block_set(self, block_set: BlockSet, table_id: int):
        SQL_CHECK(insert_block(block_set.block, False, f"blocks_{self.mainnet_idx}_{table_id}"))
        SQL_CHECK(insert_collections(
            block_set.collections, f"collections_{self.mainnet_idx}_{table_id}"
        ))
        # SQL_CHECK(insert_transactions(block_set.txs, block_set.tx_results, block_set.tx_ids))
        assert len(block_set.tx_ids) == len(block_set.txs) \
                and len(block_set.txs) == len(block_set.tx_results)
        for i in range(len(block_set.txs)):
            SQL_CHECK(
                insert_transaction(
                    block_set.txs[i],
                    block_set.tx_results[i],
                    block_set.tx_ids[i],
                    False,
                    f"transactions_{self.mainnet_idx}_{table_id}"
                )
            )
        SQL_CHECK(insert_events(block_set.events, f"events_{self.mainnet_idx}_{table_id}"))


    def __insert_data_loop(self):
        print(f"Start thread to insert block data into database.")
        while self.is_fetching:
            if self.insert_q.empty():
                time.sleep(0.1)
                if not self.is_fetching:
                    break
            else:
                block_set: BlockSet = self.insert_q.get()
                table_id: int = block_set.custom
                self.__insert_block_set(block_set, table_id)
        while not self.insert_q.empty():
            block_set: BlockSet = self.insert_q.get()
            table_id: int = block_set.custom
            self.__insert_block_set(block_set, table_id)
        print(f"Inserting loop finished!")

