#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Bubble.hpp"
#include "Insertion.hpp"
#include "Selection.hpp"
#include "util.hpp"

#define NO_OF_TESTS     3
#define NO_OF_ELEMENTS  5

typedef enum {
    SORT_BUBBLE = 0,
    SORT_INSERTION,
    SORT_SELECTION
} SortEngineIdType;

std::map<SortEngineIdType, std::string> SortEngineMap = {
    {SORT_BUBBLE, "Bubble"},
    {SORT_INSERTION, "Insertion"},
    {SORT_SELECTION, "Selection"}
};

static inline void display_usage(char * exec_name) {
    LOG("Usage:");
    LOG((std::string("  ") + exec_name + " <Sorting Engine ID>").c_str());

    for (auto engineId : SortEngineMap) {
        LOG(
            (std::string("  ") + std::to_string(engineId.first) + " -> " + engineId.second).c_str()
        );
    }
}

int main(int argc, char ** argv) {
    srand(time(NULL));

    std::vector<int> test_data;
    std::vector<int> sorted_data;

    std::unique_ptr<alg::ISort> pSortEngine;

    if (1 < argc) {
        switch (std::stoi(argv[1])) {
            case SORT_INSERTION:
                pSortEngine.reset(new alg::sort::Insertion());
                break;

            case SORT_SELECTION:
                pSortEngine.reset(new alg::sort::Selection());
                break;

            case SORT_BUBBLE:
                pSortEngine.reset(new alg::sort::Bubble());
                break;
            default:
                display_usage(argv[0]);
                exit(1);
        }
    } else {
        pSortEngine.reset(new alg::sort::Bubble());
    }

    for (auto i = 0; i < NO_OF_TESTS; i++) {
        test_data = rng(NO_OF_ELEMENTS, 0, 255);
        LOG(("Original: " + arr2str(test_data)).c_str());

        // sorted_data.clear();
        sorted_data = pSortEngine->Proceed(test_data);
        LOG(("-> Ascending: " + arr2str(sorted_data)).c_str());
        pSortEngine->rnr();
        NEWLINE();

        // sorted_data.clear();
        sorted_data = pSortEngine->Proceed(test_data, false);
        LOG(("-> Descending: " + arr2str(sorted_data)).c_str());
        pSortEngine->rnr();
        NEWLINE();
    }

    return 0;
}
