#ifndef __SELECTION_HPP__
#define __SELECTION_HPP__

#include <string>
#include <vector>

#include "sort.hpp"

namespace alg {
namespace sort {

class Selection : public ISort {
public:
    Selection(void) {}
    std::vector<int> Proceed(const std::vector<int> &data, bool ascending = true) override {
        std::vector<int> sorted(data);

        size_t j, k;
        int tmp;

        for (size_t i = 0; i < (sorted.size() - 1); i++) {
            j = i + 1;
            k = i;

            while (sorted.size() > j) {
                if (
                    (ascending && (0 < _compare(sorted[k], sorted[j]))) ||
                    ((!ascending) && (0 > _compare(sorted[k], sorted[j])))
                ) {
                    k = j;
                }

                j++;
            }

            if (i != k) {
                _swap(sorted, i, k);
            }
        }

        return sorted;
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Selection";
    }

};  // class Selection

}   // namespace sort
}   // namespace alg

#endif // __SELECTION_HPP__
