#ifndef __ISORT_H__
#define __ISORT_H__

#include <string>
#include <vector>

#include "util.hpp"

namespace alg {

class ISort {
public:
    ISort(void) : mCmpCount(0), mSwapCount(0) {}

    virtual std::vector<int> Proceed(const std::vector<int> &data, bool ascending = true) = 0;
    virtual std::string getIdentifier(void) {
        return "alg.ISort";
    }

    void rnr(void) {
        LOG(("[" + getIdentifier() + "] Summary:").c_str());
        LOG(("* Comparison: " + std::to_string(mCmpCount)).c_str());
        LOG(("* Swap      : " + std::to_string(mSwapCount)).c_str());

        reset();
    }

    void reset(void) {
        mCmpCount = 0;
        mSwapCount = 0;
    }

protected:
    int _compare(int a, int b) {
        mCmpCount++;
        if (a > b) {
            return 1;
        } else if (a == b) {
            return 0;
        } else {
            return -1;
        }
    }

    void _swap(std::vector<int> &data, const int &i, const int &j) {
        mSwapCount++;

        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    int mCmpCount;
    int mSwapCount;
};  // class ISort

}   // namespace alg

#endif // __ISORT_H__
