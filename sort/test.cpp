#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Bubble.hpp"
#include "Insertion.hpp"
#include "Selection.hpp"
#include "Quick.hpp"

#include "util/misc.hpp"
#include "util/profiling.hpp"

#define NO_OF_TESTS     3
#define NO_OF_ELEMENTS  10

typedef enum {
    SORT_BUBBLE = 0,
    SORT_INSERTION,
    SORT_SELECTION,
    SORT_QUICK
} SortEngineIdType;

std::map<SortEngineIdType, std::string> SortEngineMap = {
    {SORT_BUBBLE, "Bubble"},
    {SORT_INSERTION, "Insertion"},
    {SORT_SELECTION, "Selection"},
    {SORT_QUICK, "Quick"}
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

    util::Profiler profiler;
    const int timer_id = 0;
    std::string msg;

    std::vector<int> test_data;
    std::vector<int> sorted_data;

    std::unique_ptr<alg::sort::ISort> pSortEngine;

    if (1 < argc) {
        switch (std::stoi(argv[1])) {
            case SORT_BUBBLE:
                pSortEngine.reset(new alg::sort::Bubble());
                break;

            case SORT_INSERTION:
                pSortEngine.reset(new alg::sort::Insertion());
                break;

            case SORT_SELECTION:
                pSortEngine.reset(new alg::sort::Selection());
                break;

            case SORT_QUICK:
                pSortEngine.reset(new alg::sort::Quick());
                break;

            default:
                display_usage(argv[0]);
                exit(1);
        }
    } else {
        pSortEngine.reset(new alg::sort::Bubble());
    }

    for (auto i = 0; i < NO_OF_TESTS; i++) {
        test_data = util::rng(NO_OF_ELEMENTS, 0, 255);
        msg = std::to_string(i) + ". Original: " + util::arr2str(test_data);
        LOG(msg.c_str());

        sorted_data = test_data;
        profiler.start(timer_id);
        pSortEngine->Proceed(sorted_data);
        auto duration = profiler.stop(timer_id, util::TIME_UNIT_NANOSECOND);
        msg = "-> Ascending: " + util::arr2str(sorted_data);
        LOG(msg.c_str());

        msg = "-> Duration: " + std::to_string(duration) + " (ns)";
        LOG(msg.c_str());

        msg = "-> " + pSortEngine->rnr();
        LOG(msg.c_str());
        NEWLINE();

        sorted_data = test_data;
        pSortEngine->Proceed(sorted_data, false);
        duration = profiler.stop(timer_id, util::TIME_UNIT_NANOSECOND);

        msg = "-> Descending: " + util::arr2str(sorted_data);
        LOG(msg.c_str());

        msg = "-> Duration: " + std::to_string(duration) + " (ns)";
        LOG(msg.c_str());

        msg = "-> " + pSortEngine->rnr();
        LOG(msg.c_str());
        NEWLINE();
    }

    return 0;
}
