#include "fetch_entities_utils.h"

void FetchBlockData(int start_height, int end_height, std::string url)
{
    try {
        gflow::FlowClient client;
        client.Connect(url);

        char file_name[50];
        sprintf(file_name, "Blocks_%d_%d.csv", start_height, end_height);
        std::ofstream fs;
        fs.open(file_name, std::ofstream::out);
        CHECK(fs.is_open());
        // "block_id", "parent_id", "timestamp", "height"
        // "total_seals", "collection_cnt", "collections"

        flow::entities::Block raw_block;
        gflow::GBlock block;

        for (uint64_t i = start_height; i <= end_height; ++i) {
            client.GetBlockByHeight(i, &raw_block);
            block = gflow::ConvertToCustomEntity(raw_block);
            fs << block.id << ','
            << block.parent_id << ','
            << block.second << '.'
            << std::setfill('0') << std::setw(6) << block.nano_sec / 1000 << ','
            << block.height << ','
            << block.seal_num << ','
            << block.collections.size();

            for (int c = 0; c < block.collections.size(); ++c) {
                fs << ',' << block.collections[c];
            }
            fs << '\n';

            if (i % 100 == 0) {
                fs.flush();
                printf("Reach %d\n", i);
            }
        }

        std::cout << "Fetch block success !!!" << std::endl;

        // fs.close();
    }
    catch (std::exception& e) {
        printf("Exception: %s\n", e.what());
    }

}


void FetchBlockHeaderData(int start_height, int end_height, std::string url)
{
    try {
        gflow::FlowClient client;
        client.Connect(url);

        char file_name[50];
        sprintf(file_name, "block_header.csv");
        std::ofstream fs;
        fs.open(file_name, std::ofstream::out);
        CHECK(fs.is_open());

        flow::entities::BlockHeader raw_header;
        gflow::GBlockHeader header;

        for (uint64_t i = start_height; i < end_height; ++i) {
            client.GetBlockHeaderByHeight(i, &raw_header);
            header = gflow::ConvertToCustomEntity(raw_header);
        }
    }
    catch (std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
}


void FetchCollectionData(std::string collection_list_file,
                            std::string save_path,
                            std::string url)
{
    try {
        gflow::FlowClient client;
        client.Connect(url);

        std::ofstream ofs;
        ofs.open(save_path, std::ofstream::out);
        CHECK(ofs.is_open());

        std::ifstream f_collection_list;
        f_collection_list.open(collection_list_file);
        CHECK(f_collection_list.is_open());

        flow::entities::Collection raw_col;
        gflow::GCollection collection;

        std::vector<std::string> collection_ids;
        while (!f_collection_list.eof()) {
            std::string collection_id;
            f_collection_list >> collection_id;
            if (collection_id.size() != 64) {
                printf("Wrong collection format, %s\n", collection_id.c_str());
                continue;
            }
            collection_ids.push_back(std::move(collection_id));
        }

        printf("%d collections to be fetched.\n", collection_ids.size());
        fflush(stdout);
        for (std::string& id: collection_ids) {
            client.GetCollectionByID(gflow::HexStrToSHA256(id), &raw_col);
            collection = gflow::ConvertToCustomEntity(raw_col);
            ofs << collection.id << ','
            << collection.transaction_id.size();

            for (int i = 0; i < collection.transaction_id.size(); ++i) {
                ofs << ',' << collection.transaction_id[i];
            }
            ofs << '\n';
        }

        printf("Fetch collections success !!!\n");

        f_collection_list.close();
        ofs.close();
    }
    catch (std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
}

void FetchTransactionData(std::string tx_id_list_file, 
                            std::string save_path, 
                            std::string url)
{
    try {
        gflow::FlowClient client;
        client.Connect(url);

        // std::ofstream ofs;
        // ofs.open(save_path, std::ofstream::out);
        // CHECK(ofs.is_open());

        std::ifstream f_tx_id_list;
        f_tx_id_list.open(tx_id_list_file);
        CHECK(f_tx_id_list.is_open());
        std::vector<std::string> tx_ids;

        while (!f_tx_id_list.eof()) {
            std::string tx_id;
            f_tx_id_list >> tx_id;
            if (tx_id.size() != 64) {
                printf("Wrong transaction format, %s\n", tx_id.c_str());
                continue;
            }
            tx_ids.push_back(std::move(tx_id));
        }
        printf("%d transactions to be fetched.\n", tx_ids.size());
        fflush(stdout);

        flow::entities::Transaction raw_tx_result;
        gflow::GTransaction tx_result;
        for (std::string& id: tx_ids) {
            client.GetTransaction(gflow::HexStrToSHA256(id), &raw_tx_result);
            tx_result = gflow::ConvertToCustomEntity(raw_tx_result);
            printf("id: %s, tx num: %lld, event size: %lld\n",
                    exe_result.block_id.c_str(),
                    exe_result.chunks.size(),
                    exe_result.service_events.size());
            for (int i = 0; i < exe_result.chunks.size(); ++i) {
                auto& chunk = exe_result.chunks[i];
                printf("tx num: %u, collection_idx: %u, event_c: %s\n", 
                        chunk.number_of_transactions,
                        chunk.collection_index,
                        // gflow::Bin2HexStr(chunk.start_state).c_str(),    
                        gflow::Bin2HexStr(chunk.event_collection).c_str());
            }
        }
    }
    catch (std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
}

void FetchEventData(int start_height, int end_height, std::string url)
{

}

void FetchAccountData(int start_height, int end_height, std::string url)
{

}

void FetchExecutionResultData(std::string block_id_list_file, 
                                std::string save_path, 
                                std::string url)
{
    try {
        gflow::FlowClient client;
        client.Connect(url);

        // std::ofstream ofs;
        // ofs.open(save_path, std::ofstream::out);
        // CHECK(ofs.is_open());

        std::ifstream f_block_id_list;
        f_block_id_list.open(block_id_list_file);
        CHECK(f_block_id_list.is_open());
        std::vector<std::string> block_ids;

        while (!f_block_id_list.eof()) {
            std::string block_id;
            f_block_id_list >> block_id;
            if (block_id.size() != 64) {
                printf("Wrong collection format, %s\n", block_id.c_str());
                continue;
            }
            block_ids.push_back(std::move(block_id));
        }
        printf("%d collections to be fetched.\n", block_ids.size());
        fflush(stdout);

        flow::entities::ExecutionResult raw_exe_result;
        gflow::GExecutionResult exe_result;
        for (std::string& id: block_ids) {
            client.GetExecutionResultForBlockID(gflow::HexStrToSHA256(id), &raw_exe_result);
            exe_result = gflow::ConvertToCustomEntity(raw_exe_result);
            printf("id: %s, tx num: %lld, event size: %lld\n",
                    exe_result.block_id.c_str(),
                    exe_result.chunks.size(),
                    exe_result.service_events.size());
            for (int i = 0; i < exe_result.chunks.size(); ++i) {
                auto& chunk = exe_result.chunks[i];
                printf("tx num: %u, collection_idx: %u, event_c: %s\n", 
                        chunk.number_of_transactions,
                        chunk.collection_index,
                        // gflow::Bin2HexStr(chunk.start_state).c_str(),    
                        gflow::Bin2HexStr(chunk.event_collection).c_str());
            }
        }
    }
    catch (std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
}
