import asyncio
import flow_py_sdk
from flow_py_sdk import flow_client

async def test():
    async with flow_client(
            host="access.mainnet.nodes.onflow.org", port=9000
    ) as client:
        latest_block = await client.get_latest_block()
        block = await client.get_latest_block(is_sealed=False)
        print("Block ID: {}".format(block.id.hex()))
        print("Block height: {}".format(block.height))
        print("Block timestamp: [{}]".format(block.timestamp))
        print(block.block_seals[0].block_id.hex())
        for item in block.collection_guarantees:
            print(item.signatures)
            print(item.collection_id)



if __name__=="__main__":
    asyncio.run(test())
