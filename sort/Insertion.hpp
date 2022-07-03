#ifndef __INSERTION_HPP__
#define __INSERTION_HPP__

#include <string>
#include <vector>

#include "sort.hpp"

namespace alg {
namespace sort {

class Insertion : public ISort {
public:
    Insertion(void) {}
    std::vector<int> Proceed(const std::vector<int> &data, bool ascending = true) override {
        std::vector<int> sorted(data);

        for (auto i = 1; i < sorted.size(); i++) {
            int val = sorted[i];

            int j = i - 1;

            while (
                (0 <= j) &&
                (
                    (ascending && (0 < _compare(sorted[j], val))) ||
                    ((!ascending) && (0 > _compare(sorted[j], val)))
                )
            ) {
                sorted[j + 1] = sorted[j];
                j--;
            }

            sorted[j + 1] = val;
        }

        return sorted;
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Insertion";
    }

};  // class Insertion

}   // namespace sort
}   // namespace alg

#endif // __INSERTION_HPP__
