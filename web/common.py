from typing import Tuple
from typing import Dict
from typing import List
import json

from scipy.fft import idst

class Block:
    def __init__(self):
        self.height = 0
        self.id = ""
        self.parent_id = ""
        self.timestamp = ""
        self.seal_num = ""
        self.collection_num = ""
        self.collections = []

    def __init__(self,
                height: int, 
                id: str, 
                parent_id: str, 
                timestamp: str, 
                seal_num: int, 
                collection_num: int, 
                collections: List[str]):
        self.height = height
        self.id = id
        self.parent_id = parent_id
        self.timestamp = timestamp
        self.seal_num = seal_num
        self.collection_num = collection_num
        self.collections = collections

    def ToString(self) -> str:
        block_str = f"ID: {self.id}\n"\
            f"Parent ID: {self.parent_id}\n"\
            f"Height: {self.height}\n"\
            f"Timestamp: {self.timestamp}\n"\
            f"Seal Number: {self.seal_num}\n"\
            f"Collection Number: {self.collection_num}\n"\
            f"Collections: \n\n"
        for c in self.collections:
            block_str += '\t' + c + '\n'
        return block_str

    def ToDict(self) -> Dict:
        block_dict = {}
        block_dict["id"] = self.id
        block_dict["parent_id"] = self.parent_id
        block_dict["height"] = self.height
        block_dict["timestamp"] = self.timestamp
        block_dict["seal_number"] = self.seal_num
        block_dict["collection_number"] = self.collection_num
        block_dict["collections"] = self.collections
        # ret = {"blocks": [block_dict]}
        return block_dict
        
    def ToJson(self) -> str:
        return json.dumps({"blocks": [self.ToDict()]})


class Collection:
    def __init__(self):
        self.id = ""
        self.transaction_ids = []

    def __init__(self, id: str, transaction_ids: List[str]):
        self.id = id
        self.transaction_ids = transaction_ids

    def ToString(self) -> str:
        collection_str = f"ID: {self.id}\n"\
            f"Transactions: \n"
        for tx_id in self.transaction_ids:
            collection_str += f"\t{tx_id}\n"
        return collection_str

    def ToDict(self) -> Dict:
        collection_dict = {}
        collection_dict["id"] = self.id
        collection_dict["transaction"] = self.transaction_ids
        return collection_dict

    def ToJson(self) -> str:
        return json.dumps({"collections"})
