#include "utils.h"
#include "FlowClient.h"

void FetchBlockData(int start_height, int end_height, std::string url);

void FetchBlockHeaderData(int start_height, int end_height, std::string url);

void FetchCollectionData(std::string collection_list_file, 
                            std::string save_path, 
                            std::string url);

void FetchTransactionData(std::string tx_id_list_file, 
                                std::string save_path, 
                                std::string url);

void FetchEventData(int start_height, int end_height, std::string url);

void FetchAccountData(int start_height, int end_height, std::string url);

void FetchExecutionResultData(std::string block_id_list_file, 
                                std::string save_path, 
                                std::string url);
