#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "data.hpp"

void parse(
    const std::string &path, 
    std::vector<std::string> &genes, std::vector<int> &healths,
    std::vector<StrandType> &strands
) {
    std::ifstream fr(path.c_str(), std::ifstream::in);
    std::string line;

    std::cout << "Parsing 1st line ..." << std::endl;
    // Number of genes
    std::getline(fr, line);
    size_t count = std::stoi(line);
    
    std::cout << "Parsing 2nd line ..." << std::endl;
    // Genes
    std::getline(fr, line);
    size_t p0 = 0;
    size_t p1 = line.find(" ", p0);
    size_t i = 0;

    while ((std::string::npos != p1) && (count > i++)) {
        genes.push_back(line.substr(p0, p1 - p0));
        p0 = p1 + 1;
        p1 = line.find(" ", p0);
    }

    if (line.length() > p0) {
        genes.push_back(line.substr(p0));
    }

    if (count != genes.size()) {
        std::cout << "Invalid number of genes!" << std::endl;
        return;
    }

    std::cout << "Parsing 3rd line ..." << std::endl;
    // Healths
    std::getline(fr, line);
    p0 = 0;
    p1 = line.find(" ", p0);

    i = 0;
    while ((std::string::npos != p1) && (count > i++)) {
        healths.push_back(std::stoi(line.substr(p0, p1 - p0)));
        p0 = p1 + 1;
        p1 = line.find(" ", p0);
    }

    if (line.length() > p0) {
        healths.push_back(std::stoi(line.substr(p0)));
    }

    if (count != healths.size()) {
        std::cout << "Invalid number of health values!" << std::endl;
        return;
    }

    std::cout << "Parsing 4th line ..." << std::endl;
    // Number of strands
    std::getline(fr, line);
    count = std::stoi(line);

    std::cout << "Parsing strands ..." << std::endl;
    // Strands
    i = 0;
    while ((count > i++) && std::getline(fr, line)) {
        StrandType st;

        p0 = 0;
        p1 = line.find(" ", p0);

        st.start = std::stoi(line.substr(p0, p1 - p0));

        p0 = p1 + 1;
        p1 = line.find(" ", p0);
        st.end = std::stoi(line.substr(p0, p1 - p0));

        p0 = p1 + 1;
        p1 = line.find(" ", p0);
        st.d = line.substr(p0, p1 - p0);

        strands.push_back(st);
    }

    fr.close();
}
