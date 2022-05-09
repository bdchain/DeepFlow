import os
import sys
import json
from typing import Dict, List

from click import argument
from sql import sql_utils
from flow_py_sdk.client import entities

block_table_default      = "blocks"
tx_table_default         = "transactions"
collection_table_default = "collections"
event_table_default      = "events"

def SQL_CHECK(ret):
    if isinstance(ret, Exception):
        raise ret
    elif ret >= 0:
        return
    else:
        raise Exception(f"Insert ID {ret} is not a valid one!")


def seals_to_json(seals: List[entities.BlockSeal]) -> str:
    block_seals = []
    for seal in seals:
        seal_dict = {}
        seal_dict["block_id"] = seal.block_id.hex()
        seal_dict["execution_receipt_id"] = seal.execution_receipt_id.hex()
        exe_receipt_sig_hex = [sig.hex() for sig in seal.execution_receipt_signatures]
        seal_dict["execution_receipt_signatures"] = exe_receipt_sig_hex
        result_approval_sig_hex = [sig.hex() for sig in seal.result_approval_signatures]
        seal_dict["result_approval_signatures"] = result_approval_sig_hex
        block_seals.append(seal_dict)
    return json.dumps({"block_seals": block_seals})

def collection_guarantees_to_json(guarantees: List[entities.CollectionGuarantee]) -> str:
    collection_guarantees = []
    for g in guarantees:
        guarantee_dict = {}
        guarantee_dict["collection_id"] = g.collection_id.hex()
        sig_hex = [sig.hex() for sig in g.signatures]
        guarantee_dict["signatures"] = sig_hex
        collection_guarantees.append(guarantee_dict)
    return json.dumps({"collection_guarantees": collection_guarantees})

def signatures_to_json(signatures: List[bytes]) -> str:
    signature_list = [sig.hex() for sig in signatures]
    return json.dumps({"signatures": signature_list})

def tx_ids_to_json(tx_ids: List[bytes]) -> str:
    tx_id_list = [tx_id.hex() for tx_id in tx_ids]
    return json.dumps({"transaction_ids": tx_id_list})

def arguments_to_json(args: List[bytes]) -> str:
    arg_list = [arg.decode("utf-8") for arg in args]
    return json.dumps({"arguments": arg_list})

def proposal_key_to_json(proposal_key: entities.TransactionProposalKey) -> str:
    proposal_key_dict = {}
    proposal_key_dict["address"] = proposal_key.address.hex()
    proposal_key_dict["key_id"] = proposal_key.key_id
    proposal_key_dict["sequence_number"] = proposal_key.sequence_number
    return json.dumps(proposal_key_dict)

def authorizers_to_json(authorizers: List[bytes]) -> str:
    auth_list = [auth.hex() for auth in authorizers]
    return json.dumps({"authorizers": auth_list})

def payload_signatures_to_json(payload_sigs: List[entities.TransactionSignature]) -> str:
    sig_list = []
    for sig in payload_sigs:
        sig_dict = {}
        sig_dict["address"] = sig.address.hex()
        sig_dict["key_id"] = sig.key_id
        sig_dict["signature"] = sig.signature.hex()
        sig_list.append(sig_dict)
    return json.dumps({"payload_signatures": sig_list})

def envelope_signatures_to_json(envelope_sigs: List[entities.TransactionSignature]) -> str:
    sig_list = []
    for sig in envelope_sigs:
        sig_dict = {}
        sig_dict["address"] = sig.address.hex()
        sig_dict["key_id"] = sig.key_id
        sig_dict["signature"] = sig.signature.hex()
        sig_list.append(sig_dict)
    return json.dumps({"envelope_signatures": sig_list})

def insert_block(
    block: entities.Block,
    update_insert: bool = False,
    table: str = block_table_default
):
    entry = {}
    entry["height"] = block.height
    entry["block_id"] = block.id.hex()
    entry["parent_id"] = block.parent_id.hex()
    entry["timestamp"] = block.timestamp.timestamp()
    entry["collections"] = collection_guarantees_to_json(block.collection_guarantees)
    entry["seals"] = seals_to_json(block.block_seals)
    entry["signatures"] = signatures_to_json(block.signatures)

    if update_insert:
        insert_id = sql_utils.insert_update_data(entry, table)
    else:
        insert_id = sql_utils.insert_data(entry, table)
    return insert_id
    

def insert_collection(
    collection: entities.Collection,
    update_insert: bool = False,
    table: str = collection_table_default
):
    entry = {}
    entry["collection_id"] = collection.id
    entry["tx_ids"] = tx_ids_to_json(collection.transaction_ids)
    
    if update_insert:
        insert_id = sql_utils.insert_update_data(entry, table)
    else:
        insert_id = sql_utils.insert_data(entry, table)
    return insert_id

# Note: tx_id as a independent param is essential here since
# tx_id is not included in native entities.Transaction structure
def insert_transaction(
    tx: entities.Transaction,
    tx_result: entities.TransactionResultResponse,
    tx_id: bytes,
    update_insert: bool = False,
    table: str = tx_table_default
):
    entry = {}
    entry["tx_id"] = tx_id.hex()
    entry["script"] = tx.script.decode("utf-8")
    entry["arugments"] = arguments_to_json(tx.arguments)
    entry["reference_block_id"] = tx.reference_block_id.hex()
    entry["gas_limit"] = tx.gas_limit
    entry["proposal_key"] = proposal_key_to_json(tx.proposal_key)
    entry["payer"] = tx.payer.hex()
    entry["authorizers"] = authorizers_to_json(tx.authorizers)
    entry["payload_signatures"] = payload_signatures_to_json(tx.payload_signatures)
    entry["envelope_signatures"] = envelope_signatures_to_json(tx.envelope_signatures)
    entry["status"] = int(tx_result.status)
    entry["status_code"] = tx_result.status_code
    entry["error_message"] = tx_result.error_message

    if update_insert:
        insert_id = sql_utils.insert_update_data(entry, table)
    else:
        insert_id = sql_utils.insert_data(entry, table)
    return insert_id


def insert_event(
    event: entities.Event,
    update_insert: bool = False,
    table: str = event_table_default
):
    entry = {}
    entry["type"] = event.type
    entry["tx_id"] = event.transaction_id.hex()
    entry["tx_index"] = event.transaction_index
    entry["event_index"] = event.event_index
    entry["payload"] = event.payload.decode("utf-8")

    if update_insert:
        insert_id = sql_utils.insert_update_data(entry, table)
    else:
        insert_id = sql_utils.insert_data(entry, table)
    return insert_id


def insert_events(
    events: List[entities.Event],
    table: str = event_table_default
):
    entries = []
    for event in events:
        entry = {}
        entry["type"] = event.type
        entry["tx_id"] = event.transaction_id.hex()
        entry["tx_index"] = event.transaction_index
        entry["event_index"] = event.event_index
        entry["payload"] = event.payload.decode("utf-8")
        entries.append(entry)

    insert_id = sql_utils.insert_data_list(entries, table)
    return insert_id

