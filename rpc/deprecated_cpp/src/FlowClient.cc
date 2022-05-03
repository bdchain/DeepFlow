#include "FlowClient.h"

using namespace flow;

namespace gflow {

FlowClient::FlowClient()
    : connected_(false)
{
}

FlowClient::~FlowClient()
{
}

Status FlowClient::Connect(const std::string url)
{
    std::shared_ptr<grpc::Channel> channel 
        = grpc::CreateChannel(url, grpc::InsecureChannelCredentials());

    stub_ = access::AccessAPI::NewStub(channel);
    connected_ = true;

    return OkStatus();
}

Status FlowClient::Connect(const std::string host, const int port)
{
    host_ = host;
    port_ = port;
    std::string port_str = std::to_string(port_);
    std::string url = host_ + ":" + port_str;

    std::shared_ptr<grpc::Channel> channel 
        = grpc::CreateChannel(url, grpc::InsecureChannelCredentials());

    stub_ = access::AccessAPI::NewStub(channel);
    connected_ = true;

    return OkStatus();
}

Status FlowClient::DisConnect()
{
    connected_ = false;

    return OkStatus();
}

Status FlowClient::Ping()
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::PingRequest req;
    access::PingResponse ping_res;
    grpc::Status status = stub_->Ping(&ctx, req, &ping_res);
    GRPC_STATUS_CHECK(status);

    return OkStatus();
}


Status FlowClient::GetTransaction(std::string id, entities::Transaction* tx)
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::GetTransactionRequest req;
    req.set_id(id);
    access::TransactionResponse tx_res;
    grpc::Status status = stub_->GetTransaction(&ctx, req, &tx_res);
    GRPC_STATUS_CHECK(status);
    
    *tx = tx_res.transaction();

    return OkStatus();
}

Status FlowClient::GetTransactionResult(std::string id, TransactionResult* tx_result)
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::GetTransactionRequest req;
    req.set_id(id);
    access::TransactionResultResponse tx_result_res;
    grpc::Status status = stub_->GetTransactionResult(&ctx, req, &tx_result_res);
    GRPC_STATUS_CHECK(status);

    tx_result->status = tx_result_res.status();
    tx_result->status_code = tx_result_res.status_code();
    tx_result->error_message = tx_result_res.error_message();
    auto& events = tx_result->events;
    events.resize(tx_result_res.events().size());
    for (int i = 0; i < events.size(); ++i) {
        events[i] = tx_result_res.events()[i];
    }
    tx_result->block_id = tx_result_res.block_id();
}

Status FlowClient::GetBlockHeaderByHeight(uint64_t height, flow::entities::BlockHeader* block_header)
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::GetBlockHeaderByHeightRequest req;
    req.set_height(height);
    access::BlockHeaderResponse raw_header_res;
    grpc::Status status = stub_->GetBlockHeaderByHeight(&ctx, req, &raw_header_res);
    GRPC_STATUS_CHECK(status);

    *block_header = raw_header_res.block();

    return OkStatus();
}

Status FlowClient::GetBlockByHeight(uint64_t height, entities::Block* block)
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::GetBlockByHeightRequest req;
    req.set_height(height);
    access::BlockResponse block_res;
    grpc::Status status = stub_->GetBlockByHeight(&ctx, req, &block_res);
    GRPC_STATUS_CHECK(status);

    // message Block {
    //     bytes id = 1;
    //     bytes parent_id = 2;
    //     uint64 height = 3;
    //     google.protobuf.Timestamp timestamp = 4;
    //     repeated CollectionGuarantee collection_guarantees = 5;
    //     repeated BlockSeal block_seals = 6;
    //     repeated bytes signatures = 7;
    //     repeated ExecutionReceiptMeta execution_receipt_metaList = 8;
    //     repeated ExecutionResult execution_result_list = 9;
    // }
    *block = block_res.block();

    return OkStatus();
}

Status FlowClient::GetCollectionByID(std::string id, flow::entities::Collection* collection)
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::GetCollectionByIDRequest req;
    req.set_id(id);
    access::CollectionResponse col_res;
    grpc::Status status = stub_->GetCollectionByID(&ctx, req, &col_res);
    GRPC_STATUS_CHECK(status);

    // message Collection {
    //     bytes id = 1;
    //     repeated bytes transaction_ids = 2;
    // }
    *collection = col_res.collection();

    return OkStatus();
}

Status FlowClient::GetExecutionResultForBlockID(std::string id, flow::entities::ExecutionResult* exe_result)
{
    if (!connected_)
        return NotConnectedStatus();

    grpc::ClientContext ctx;
    access::GetExecutionResultForBlockIDRequest req;
    req.set_block_id(id);
    access::ExecutionResultForBlockIDResponse res;
    grpc::Status status = stub_->GetExecutionResultForBlockID(&ctx, req, &res);
    GRPC_STATUS_CHECK(status);

    *exe_result = res.execution_result();

    return OkStatus();
}

} // namespace gflow

