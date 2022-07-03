#ifndef __BUBBLE_H__
#define __BUBBLE_H__

#include <string>
#include <vector>

#include "ISort.hpp"
#include "util.hpp"

namespace alg {
namespace sort {

class Bubble : public ISort {
public:
    Bubble(void) {}
    std::vector<int> Proceed(const std::vector<int> &data, bool ascending = true) override {
        std::vector<int> sorted(data);
        bool swap_flag = false;

        for (auto i = 0; i < sorted.size(); i++) {
            for (auto j = 0; j < sorted.size() - i - 1; j++) {
                bool to_swap =
                    (ascending && (0 < _compare(sorted[j], sorted[j + 1]))) ||
                    ((!ascending) && (0 > _compare(sorted[j], sorted[j + 1])));

                if (to_swap) {
                    _swap(sorted, j, j + 1);
                    swap_flag = true;
                }
            }

            if (!swap_flag) {
                break;
            }
        }

        return sorted;
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Bubble";
    }

};  // class Bubble

}   // namespace sort
}   // namespace alg

#endif // __BUBBLE_H__
