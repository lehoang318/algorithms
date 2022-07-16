#ifndef __RMERGE_HPP__
#define __RMERGE_HPP__

#include <string>
#include "sort.hpp"

namespace alg {
namespace sort {

class RMerge : public ISort {
public:
    RMerge(void) : mAscending(true) {}

    void Proceed(std::vector<int> &data, bool ascending = true) override {
        mAscending = ascending;
        mSort(data, 0, data.size() - 1);
    }

private:
    void mSort(std::vector<int> &data, size_t first, size_t last) {
        if (first < last) {
            size_t mid = (first + last) / 2;
            mSort(data, first, mid);
            mSort(data, mid + 1, last);
            merge(data, first, mid, last);
        }
    }

    void merge(std::vector<int> &data, size_t first, size_t mid, size_t last) {
        std::vector<int> merged(last - first + 1, 0);
        size_t i = first;
        size_t j = mid + 1;
        size_t k = 0;

        while ((mid >= i) && (last >= j)) {
            if (
                (mAscending && (0 < _compare(data[j], data[i]))) ||
                ((!mAscending) && (0 > _compare(data[j], data[i])))
            ) {
                merged[k++] = data[i++];
            } else {
                merged[k++] = data[j++];
            }
        }

        while (mid >= i) {
            merged[k++] = data[i++];
        }

        while (last >= j) {
            merged[k++] = data[j++];
        }

        for (i = 0; i < last - first + 1; i++) {
            data[first + i] = merged[i];
        }
    }

    bool mAscending;
};

}   // namespace sort
}   // namespace alg

#endif // __RMERGE_HPP__
