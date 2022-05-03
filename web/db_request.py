from db_connector import DBConnector
from common import *

db = DBConnector()

# net_root = [7601063, 8742959, 9737133, 9992020, 12020337, 
#             12609237, 13404174, 13950742, 14892104, 15791891,
#             16755602, 17544523, 18587478, 19050753, 21291692,
#             23830813, 26391756]

# TODO mainnet 16 not considered yet
net_root = [7601063, 8742959, 9737133, 9992020, 12020337, 
            12609237, 13404174, 13950742, 14892104, 15791891,
            16755602, 17544523, 18587478, 19050753, 21291692,
            23830813]

# TODO improve efficiency of the func
def choose_net_by_height(height: int) -> int:
    # if height < net_root[0] or height >= net_root[-1]:
    #     return -1
    for i in range(len(net_root) - 1):
        if height >= net_root[i] and height < net_root[i+1]:
            return i + 1
    return -1

def block_height_valid(height: str) -> bool:
    return height >= net_root[0] and height < net_root[-1]

def block_height_range_valid(start_height: int, end_height: int) -> bool:
    return end_height >= start_height and \
        start_height >= net_root[0] and end_height < net_root[-1]

def _retrieve_block_from_db_entry(entry: tuple) -> Block:
    height = entry[0]
    id = entry[1]
    parent_id = entry[2]
    timestamp = entry[3]
    seal_num = entry[4]
    collection_num = entry[5]
    packed_col = entry[6]
    collections = []
    for i in range(collection_num):
        c = packed_col[64*i:64*(i+1)]
        collections.append(c)
    return Block(height, id, parent_id, timestamp, 
                seal_num, collection_num, collections)


def get_block_by_height(height: int) -> Block:
    if not block_height_valid(height):
        return None

    sql = f"SELECT * FROM mainnet_all "\
          f"WHERE Height={height}"
    db.execute(sql)
    result = db.fetchall()
    assert len(result) == 1

    entry = result[0]
    return _retrieve_block_from_db_entry(entry)


def get_block_by_id(id: str) -> Block:
    # TODO tell if id is valid
    sql = f"SELECT * FROM mainnet_all "\
          f"WHERE ID='{id}'"
    db.execute(sql)
    result = db.fetchall()
    assert len(result) == 1

    entry = result[0]
    return _retrieve_block_from_db_entry(entry)

def get_block_by_height_range(start_height: int, end_height: int) -> List[Block]:
    if not block_height_range_valid(start_height, end_height):
        return []

    sql = f"SELECT * FROM mainnet_all "\
          f"WHERE Height>={start_height} AND Height<={end_height}"
    db.execute(sql)
    result = db.fetchall()
    assert len(result) == end_height - start_height + 1

    ret = []
    for entry in result:
        block = _retrieve_block_from_db_entry(entry)
        ret.append(block)
    return ret
    