#pragma once

#include "utils.h"

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>


namespace gflow {

class FlowClient {
public:
    FlowClient();
    ~FlowClient();

    Status Connect(const std::string url);
    Status Connect(const std::string host, const int port);
    Status DisConnect();

    Status Ping();
    Status GetTransaction(std::string id, flow::entities::Transaction* tx);
    Status GetTransactionResult(std::string id, TransactionResult* tx_result);
    Status GetBlockHeaderByHeight(uint64_t height, flow::entities::BlockHeader* block_header);
    Status GetBlockHeaderByID(std::string id, flow::entities::BlockHeader* block_header);
    Status GetBlockByHeight(uint64_t height, flow::entities::Block* block);
    Status GetBlockByID(std::string id, flow::entities::Block* block);
    Status GetCollectionByID(std::string id, flow::entities::Collection* collection);
    Status GetEventsForBlockIDs(std::vector<std::string> ids, std::vector<flow::entities::Event> events);
    Status GetEventsForHeightRange(uint64_t start_height, uint64_t end_height, std::vector<flow::entities::Event> events);
    Status GetExecutionResultForBlockID(std::string id, flow::entities::ExecutionResult* exe_result);


private:
    std::unique_ptr<flow::access::AccessAPI::Stub> stub_;

    std::string host_;
    int port_;

    bool connected_;

};


} // namespace gflow
