#ifndef __BUBBLE_HPP__
#define __BUBBLE_HPP__

#include <string>
#include <vector>

#include "sort.hpp"

namespace alg {
namespace sort {

class Bubble : public ISort {
public:
    Bubble(void) {}
    void Proceed(std::vector<int> &data, bool ascending = true) override {
        bool swap_flag = false;

        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data.size() - i - 1; j++) {
                bool to_swap =
                    (ascending && (0 < _compare(data[j], data[j + 1]))) ||
                    ((!ascending) && (0 > _compare(data[j], data[j + 1])));

                if (to_swap) {
                    _swap(data, j, j + 1);
                    swap_flag = true;
                }
            }

            if (!swap_flag) {
                break;
            }
        }
    }

    std::string getIdentifier(void) override {
        return "alg.sort.Bubble";
    }

};  // class Bubble

}   // namespace sort
}   // namespace alg

#endif // __BUBBLE_HPP__
