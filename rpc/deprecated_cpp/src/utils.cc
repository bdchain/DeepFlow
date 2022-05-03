#include "utils.h"

#include "json/json.h"

namespace gflow {

__attribute__((hot)) std::string Bin2HexStr(const std::string bin)
{
    std::string ret;
    for (int i = 0; i < bin.size(); ++i) {
        uint8_t byte = *(uint8_t*)(bin.data() + i);
        uint8_t high = byte >> 4;
        uint8_t low = byte & 0x0f;
        if (high > 9) {
            ret.push_back(static_cast<char>(high - 10 + 'a'));
        }
        else {
            ret.push_back(static_cast<char>(high + '0'));
        }
        if (low > 9) {
            ret.push_back(static_cast<char>(low - 10 + 'a'));
        }
        else {
            ret.push_back(static_cast<char>(low + '0'));
        }
    }

    return ret;
}

// use a map to optimize this func
__attribute__((hot)) std::string SHA256ToHexStr(const std::string sha256)
{
    std::string ret;
    for (int i = 0; i < sha256.size(); ++i) {
        uint8_t byte = *(uint8_t*)(sha256.data() + i);
        uint8_t high = byte >> 4;
        uint8_t low = byte & 0x0f;
        if (high > 9) {
            ret.push_back(static_cast<char>(high - 10 + 'a'));
        }
        else {
            ret.push_back(static_cast<char>(high + '0'));
        }
        if (low > 9) {
            ret.push_back(static_cast<char>(low - 10 + 'a'));
        }
        else {
            ret.push_back(static_cast<char>(low + '0'));
        }
    }

    return ret;
}

__attribute__((hot)) std::string HexStrToSHA256(const std::string hex)
{
    CHECK_PRT(hex.size() == 64, hex.c_str());
    std::string ret;
    ret.resize(32);
    for (int i = 0; i < 32; ++i) {
        char high = hex[2*i];
        char low  = hex[2*i + 1];
        if (high > '9') {
            high = high - 'a' + 10;
        }
        else {
            high = high - '0';
        }
        if (low > '9') {
            low = low - 'a' + 10;
        }
        else {
            low = low - '0';
        }
        ret[i] = (high << 4) + low;
    }
    return ret;
}

std::vector<gflow::Spork> ParseSporks(std::string spork_file)
{
    std::vector<gflow::Spork> ret(SPORK_MAINNET_CNT + 1);

    std::ifstream ifs;
    ifs.open(spork_file, std::ifstream::in);
    CHECK(ifs.is_open());

    // Parse Json File
    Json::CharReaderBuilder builder;
    std::string errs;
    Json::Value root;
    CHECK(Json::parseFromStream(builder, ifs, &root, &errs));

    Json::Value mainnet_root = root["networks"]["mainnet"];
    // candidate network
    for (int i = SPORK_MAINNET_CNT; i >= 1; --i) {
        std::string network("mainnet");
        network += std::to_string(i);
        Json::Value mainnet = mainnet_root[network];
        gflow::Spork spork;
        std::string height_str = mainnet["rootHeight"].asString();
        spork.start_height = std::atoll(height_str.c_str());
        spork.access_node  = mainnet["accessNodes"][0].asString();
        if (spork.access_node.empty()) {
            spork.access_node  = mainnet["accessNode"][0].asString();
        }
        
        if (i < SPORK_MAINNET_CNT) {
            spork.end_height = ret[i + 1].start_height - 1;
        }

        ret[i] = spork;
    }
    ret[SPORK_MAINNET_CNT].end_height = LATEST_BLOCK_HEIGHT;
    ret[SPORK_MAINNET_CNT].access_node = "access.mainnet.nodes.onflow.org:9000";

    return ret;
}

GBlock ConvertToCustomEntity(const flow::entities::Block& raw_block)
{
    GBlock ret;
    ret.id = SHA256ToHexStr(raw_block.id());
    ret.parent_id = SHA256ToHexStr(raw_block.parent_id());
    ret.height = raw_block.height();
    ret.second = raw_block.timestamp().seconds();
    ret.nano_sec = raw_block.timestamp().nanos();
    ret.seal_num = raw_block.block_seals().size();

    auto collections = raw_block.collection_guarantees();
    ret.collections.resize(collections.size());
    for (int i = 0; i < collections.size(); ++i) {
        ret.collections[i] = SHA256ToHexStr(collections[i].collection_id());
    }

    return ret;
}


// GBlockHeader ConvertToCustomEntity(const flow::entities::BlockHeader& raw_block_header)
// {

// }

GCollection ConvertToCustomEntity(const flow::entities::Collection& raw_col)
{
    GCollection ret;
    ret.id = SHA256ToHexStr(raw_col.id());

    auto txs = raw_col.transaction_ids();
    ret.transaction_id.resize(txs.size());
    for (int i = 0; i < txs.size(); ++i) {
        ret.transaction_id[i] = SHA256ToHexStr(txs[i]);
    }

    return ret;
}

GTransaction ConvertToCustomEntity(const flow::entities::Transaction& raw_tx)
{
    GTransaction ret;
    ret.script = raw_tx.script();



    return ret;
}

// GEvent ConvertToCustomEntity(const flow::entities::Event& raw_event)
// {

// }

GExecutionResult ConvertToCustomEntity(const flow::entities::ExecutionResult& raw_exe_result)
{
    GExecutionResult ret;
    ret.previous_result_id = SHA256ToHexStr(raw_exe_result.previous_result_id());
    ret.block_id = SHA256ToHexStr(raw_exe_result.block_id());

    auto chunks = raw_exe_result.chunks();
    ret.chunks.resize(chunks.size());
    for (int i = 0; i < chunks.size(); ++i) {
        ret.chunks[i].collection_index = chunks[i].collectionindex();
        ret.chunks[i].start_state = chunks[i].start_state();
        ret.chunks[i].event_collection = chunks[i].event_collection();
        ret.chunks[i].block_id = SHA256ToHexStr(chunks[i].block_id());
        ret.chunks[i].total_computation_used = chunks[i].total_computation_used();
        ret.chunks[i].number_of_transactions = chunks[i].number_of_transactions();
        ret.chunks[i].index = chunks[i].index();
        ret.chunks[i].end_state = chunks[i].end_state();
    }

    auto service_events = raw_exe_result.service_events();
    ret.service_events.resize(service_events.size());
    for (int i = 0; i < service_events.size(); ++i) {
        ret.service_events[i].type = service_events[i].type();
        ret.service_events[i].payload = service_events[i].payload();
    }

    return ret;
}

} // namespace gflow

