// #include <map>
// #include <memory>
#include <string>
#include <vector>

#include "util/misc.hpp"
#include "util/profiling.hpp"

#include "merge.hpp"
#include "Selection.hpp"

#define NO_OF_TESTS         3
#define MIN_NO_OF_ELEMENTS  5
#define MAX_NO_OF_ELEMENTS  10
#define MIN_ELEMENT_VALUE   0
#define MAX_ELEMENT_VALUE   255

int main(int argc, char ** argv) {
    // srand(time(NULL));
    srand(1);

    alg::merge::MergeEngine mergeEngine;
    alg::sort::Selection sortEngine;
    util::Profiler profiler;
    const int timer_id = 0;
    std::string msg;

    std::vector<int> test_data[2];
    std::vector<int> merged_data;
    size_t ecount;

    for (auto i = 0; i < NO_OF_TESTS; i++) {
        ecount = util::rng_integer(MIN_NO_OF_ELEMENTS, MAX_NO_OF_ELEMENTS);
        test_data[0] = util::rng_integers(ecount, MIN_ELEMENT_VALUE, MAX_ELEMENT_VALUE);
        sortEngine.Proceed(test_data[0]);

        ecount = util::rng_integer(MIN_NO_OF_ELEMENTS, MAX_NO_OF_ELEMENTS);
        test_data[1] = util::rng_integers(ecount, MIN_ELEMENT_VALUE, MAX_ELEMENT_VALUE);
        sortEngine.Proceed(test_data[1]);

        msg = std::to_string(i) + ". Original:\n";
        msg += "* 1st array: " + util::arr2str(test_data[0]) + "\n";
        msg += "* 2nd array: " + util::arr2str(test_data[1]) + "\n";
        LOG(msg.c_str());

        profiler.start(timer_id);
        merged_data = mergeEngine.Proceed(test_data[0], test_data[1]);
        auto duration = profiler.stop(timer_id, util::TIME_UNIT_NANOSECOND);
        msg = "-> Merged: " + util::arr2str(merged_data) + "\n";
        LOG(msg.c_str());

        msg = "-> Duration: " + std::to_string(duration) + " (ns)";
        LOG(msg.c_str());

        NEWLINE();
    }

    return 0;
}
