#ifndef __SORT_HPP__
#define __SORT_HPP__

#include <string>
#include <vector>

namespace alg {
namespace sort{

class ISort {
public:
    ISort(void) : mCmpCount(0), mSwapCount(0) {}
    virtual ~ISort(void) {}

    virtual void Proceed(std::vector<int> &data, bool ascending = true) = 0;
    virtual std::string getIdentifier(void) {
        return "alg.sort.ISort";
    }

    std::string rnr(void) {
        std::string report = "[" + getIdentifier() + "] Summary:\n";
        report += "* Comparison: " + std::to_string(mCmpCount) + "\n";
        report += "* Swap      : " + std::to_string(mSwapCount) + "\n";

        reset();

        return report;
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

}   // namespace sort
}   // namespace alg

#endif // __SORT_HPP__
