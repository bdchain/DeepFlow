#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

#include "common_define.h"
#include "Status.h"

#include "flow/access/access.grpc.pb.h"
#include "flow/execution/execution.pb.h"
#include "flow/entities/block.pb.h"
#include "flow/entities/block_header.pb.h"
#include "flow/entities/block_seal.pb.h"
#include "flow/entities/transaction.grpc.pb.h"
#include "flow/entities/collection.grpc.pb.h"
#include "flow/entities/execution_result.grpc.pb.h"
#include "flow/entities/event.grpc.pb.h"
#include "flow/entities/account.grpc.pb.h"

#define CHECK(condition)                             \
	do {                                             \
		if (!(condition)) {                          \
			printf(                                  \
				"Check error in file %s line %d\n",  \
				__FILE__,                            \
				__LINE__                             \
			);                                       \
			exit(1);                                 \
		}                                            \
	}                                                \
	while (0)

#define CHECK_PRT(condition, msg)                    \
	do {                                             \
		if (!(condition)) {                          \
			printf(                                  \
				"Check error in file %s line %d,"    \
				"msg: %s\n",                         \
				__FILE__,                            \
				__LINE__,                            \
				msg                                  \
			);                                       \
			exit(1);                                 \
		}                                            \
	}                                                \
	while (0)

#define GRPC_STATUS_CHECK(status)                    \
	do {                                             \
		if (!status.ok()) {                          \
			printf("Grpc Call Error, %s, %s\n",      \
				status.error_message().c_str(),      \
				status.error_details().c_str());     \
		}                                            \
	}                                                \
	while (0)

namespace gflow {

struct GBlock {
    std::string id;
    std::string parent_id;
    uint64_t height;
    int64_t second;
    int32_t nano_sec;
    uint32_t seal_num;
    std::vector<std::string> collections;
	std::vector<std::string> signatures;
};

struct GBlockHeader {
	std::string id;
	std::string parent_id;
	uint64_t height;
    int64_t second;
    int32_t nano_sec;
	std::string payload_hash;
	uint64_t view;
	std::vector<std::string> parent_voter_ids;
	std::string parent_voter_sig_data;
	std::string proposer_id;
	std::string proposer_sig_data;
	std::string chain_id;
};

struct GCollection {
    std::string id;
    std::vector<std::string> transaction_id;
};

struct GEvent {
	std::string type;
	std::string transaction_id;
	uint32_t transaction_index;
	uint32_t event_index;
	std::string payload;
};

struct TransactionResult {
	flow::entities::TransactionStatus status;
	uint32_t status_code;
	std::string error_message;
	std::vector<flow::entities::Event> events;
	std::string block_id;
};

struct GTransactionResult {
	flow::entities::TransactionStatus status;
	uint32_t status_code;
	std::string error_message;
	std::vector<GEvent> events;
	std::string block_id;
};

struct Signature {
	std::string address;
	uint32_t key_id;
	std::string signature;
};

struct GTransaction {
	std::string script;
	std::vector<std::string> arguments;
	std::string reference_block_id;
	uint64_t gas_limit;
	struct ProposalKey {
		std::string address;
		uint32_t key_id;
		uint64_t sequence_number;
	} proposal_key;
	std::string payer;
	std::vector<std::string> authorizers;
	std::vector<Signature> payload_signatures;
	std::vector<Signature> envelope_signatures;
};

struct Chunk {
	uint32_t collection_index;
	std::string start_state;
	std::string event_collection;
	std::string block_id;
	uint64_t total_computation_used;
	uint32_t number_of_transactions;
	uint64_t index;
	std::string end_state;
};

struct ServiceEvent {
	std::string type;
	std::string payload;
};

struct GExecutionResult {
	std::string previous_result_id;
	std::string block_id;
	std::vector<Chunk> chunks;
	std::vector<ServiceEvent> service_events;
	std::string execution_data_id;
};

GBlock           ConvertToCustomEntity(const flow::entities::Block&           raw_block);
GBlockHeader     ConvertToCustomEntity(const flow::entities::BlockHeader&     raw_block_header);
GCollection      ConvertToCustomEntity(const flow::entities::Collection&      raw_col);
GTransaction     ConvertToCustomEntity(const flow::entities::Transaction&     raw_tx);
GEvent           ConvertToCustomEntity(const flow::entities::Event&           raw_event);
GExecutionResult ConvertToCustomEntity(const flow::entities::ExecutionResult& raw_exe_result);

struct Spork {
	uint64_t start_height;
	uint64_t end_height;
	std::string access_node;
};

std::string Bin2HexStr(const std::string sha256);
std::string SHA256ToHexStr(const std::string sha256);
std::string HexStrToSHA256(const std::string hex);

std::vector<Spork> ParseSporks(std::string spork_file);

} // namespace gflow

