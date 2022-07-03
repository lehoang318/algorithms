#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <string>

typedef struct {
    int start;
    int end;
    std::string d;

    std::string toString(void) {
        std::string rep("");
        rep += std::to_string(start) + " - " + std::to_string(end) + " | `" + d + "`";
        return rep;
    }
} StrandType;

extern void parse(
    const std::string &path, 
    std::vector<std::string> &genes, std::vector<int> &healths,
    std::vector<StrandType> &strands
);

#endif // __DATA_HPP__
