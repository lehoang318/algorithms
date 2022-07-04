#ifndef __INSERTION_HPP__
#define __INSERTION_HPP__
#include <iostream>
#include <string>
#include <vector>

#include "sort.hpp"

namespace alg {
namespace sort {

class Insertion : public ISort {
public:
    Insertion(void) {}
    void Proceed(std::vector<int> &data, bool ascending = true) override {
        size_t j;
        bool toSwap;
        int val;

        for (size_t i = 1; i < data.size(); i++) {
            val = data[i];

            for (j = i; j > 0; j--) {
                if (ascending) {
                    toSwap = (0 < _compare(data[j - 1], val));
                } else {
                    toSwap = (0 > _compare(data[j - 1], val));
                }

                if (toSwap) {
                    data[j] = data[j - 1];
                } else {
                    break;
                }
            }

            data[j] = val;
        }
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Insertion";
    }

};  // class Insertion

}   // namespace sort
}   // namespace alg

#endif // __INSERTION_HPP__
