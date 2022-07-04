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
    void Proceed(std::vector<int> &data, bool ascending = true) override {
        size_t j, k;

        for (size_t i = 0; i < (data.size() - 1); i++) {
            j = i + 1;
            k = i;

            while (data.size() > j) {
                if (
                    (ascending && (0 < _compare(data[k], data[j]))) ||
                    ((!ascending) && (0 > _compare(data[k], data[j])))
                ) {
                    k = j;
                }

                j++;
            }

            if (i != k) {
                _swap(data, i, k);
            }
        }
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Selection";
    }

};  // class Selection

}   // namespace sort
}   // namespace alg

#endif // __SELECTION_HPP__
