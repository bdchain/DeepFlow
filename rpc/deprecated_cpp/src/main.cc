#include <gflags/gflags.h>
#include "utils.h"
#include "FlowClient.h"
#include "fetch_entities_utils.h"

DEFINE_string(entity, "block", "Specify which kind flow entity is desired");
DEFINE_int32(mainnet_idx, 1, "Specify mainnet index");

int main(int argc, char* argv[])
{

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    std::vector<gflow::Spork> sporks = gflow::ParseSporks(spork_file);
    // int mainnet_num = std::atoi(argv[1]);
    if (FLAGS_mainnet_idx < 1 || FLAGS_mainnet_idx > SPORK_MAINNET_CNT) {
        printf("Wrong mainnet index given, use number between 1 ~ %d.\n", SPORK_MAINNET_CNT);
        return -1;
    }

    gflow::Spork& spork = sporks[FLAGS_mainnet_idx];

    std::cout << "Going to fetch data ranging from height " << spork.start_height
            << " to " << spork.end_height
            << ", from access node " << spork.access_node << std::endl;
    if (FLAGS_entity == "block") {
        FetchBlockData(spork.start_height, spork.end_height, spork.access_node);
    }
    else if (FLAGS_entity == "collection") {
        FetchCollectionData("collection_list.csv", "collections.csv", spork.access_node);
    }
    else if (FLAGS_entity == "execution_result") {
        FetchExecutionResultData("../data/mainnet_15/block_list.csv", "", spork.access_node);
    }
    else if (FLAGS_entity == "transaction") {
        

    }
    else if (FLAGS_entity == "event") {


    }
    else {
        printf("Entity <%s> is invalid.\n", FLAGS_entity.c_str());
        return -1;
    }


    printf("Fetch %s Data Accomplished!", FLAGS_entity.c_str());

    return 0;
}
