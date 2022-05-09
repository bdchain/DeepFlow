import asyncio
from html import entities
import flow_py_sdk
from flow_py_sdk import flow_client
from sql.flow_sql import *
from utils import parse_spork_from_file

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
    async with flow_client(
        host="access.mainnet.nodes.onflow.org", port=9000
    ) as client:

        latest_block = await client.get_latest_block()
        latest_height = latest_block.height - 10


        print(f"Start fetching block data from height {latest_height}")
        MAX_TRIAL_CNT = 3
        for height in range(latest_height, root_height-1, -1):
            block = await client.get_block_by_height(height=height)
            # SQL_CHECK(insert_block(block))
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
                pass

                



if __name__ == "__main__":
    sporks = parse_spork_from_file()
    asyncio.run(retrieve_block_from_latest(sporks[-1][0]))
