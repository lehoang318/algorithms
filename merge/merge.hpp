#ifndef __MERGE_HPP__
#define __MERGE_HPP__

#include <string>
#include <vector>

namespace alg {
namespace merge {

class MergeEngine {
public:
    std::vector<int> Proceed(const std::vector<int> &first, const std::vector<int> &second) {
        std::vector<int> merged((first.size() + second.size()), 0);
        size_t i = 0;
        size_t j = 0;
        size_t k = 0;

        while ((first.size() > i) && (second.size() > j)) {
            if (first[i] < second[j]) {
                merged[k++] = first[i++];
            } else {
                merged[k++] = second[j++];
            }
        }

        while (first.size() > i) {
            merged[k++] = first[i++];
        }

        while (second.size() > j) {
            merged[k++] = second[j++];
        }
        return merged;
    }
};  // class MergeEngine

}   // namespace merge
}   // namespace alg

#endif // __MERGE_HPP__
