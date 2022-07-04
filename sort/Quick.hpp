#ifndef __QUICK_HPP__
#define __QUICK_HPP__

#include <string>
#include <vector>

#include "sort.hpp"

namespace alg {
namespace sort {

class Quick : public ISort {
public:
    Quick(void) : mAscending(true) {}
    void Proceed(std::vector<int> &data, bool ascending = true) override {
        mAscending = ascending;
        partition(data, 0, data.size() - 1);
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Quick";
    }

private:
    void partition(std::vector<int> &data, size_t first, size_t last) {
        if (first < last) {
            size_t i = first;
            size_t j;

            for (j = first + 1; j <= last; j++) {
                if (
                    (mAscending && (0 < _compare(data[first], data[j]))) ||
                    ((!mAscending) && (0 > _compare(data[first], data[j])))
                ) {
                    i++;
                    _swap(data, i, j);
                }
            }
            _swap(data, first, i);

            if (0 < i) {
                partition(data, first, i - 1);
            }

            partition(data, i + 1, last);
        }
    }

    bool mAscending;
};  // class Quick

}   // namespace sort
}   // namespace alg

#endif // __QUICK_HPP__
