#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "data.hpp"
#include "kmp.hpp"

using namespace std;

// #define DEBUG
// #define KMP
#ifdef KMP
#define find_substr(text, pattern)   KMPSearch(text, pattern)
#else   // KMP
int find_substr(const string &contents, const string &substr) {
    int count = 0;
    size_t pos;

    const size_t n = contents.length();
    const size_t m = substr.length();
    const size_t length = n - m;

    for (size_t i = 0; i <= length;) {
        pos = contents.find(substr, i);
        if (string::npos == pos) {
            break;
        }
        
        count++;
        i = pos + 1;
    }

    return count;
}
#endif   // KMP

unsigned long long analyze_single_strand(
    const vector<string> &genes,
    const vector<int> &healths,
    const int start, int end, string d
) {
    unsigned long long total = 0;
    int count = 0;

#if defined (DEBUG)
    cout << "Analyzing `" << d << "` ..." << endl;
#endif

    for (auto i = start; i <= end; i++) {
        count = find_substr(d, genes[i]);
        total += (unsigned long long)count * (unsigned long long)healths[i];
#if defined (DEBUG)
        cout << "  Found `" << genes[i] << "` "
            << count << " times! -> +"
            << count * healths[i]
            << endl;
#endif
    }

    return total;
}

void proceed(string ipath) {
    cout << "Analyzing `" << ipath << "` ..." << endl;

    vector<string> genes;
    vector<int> health;
    vector<StrandType> strands;

    parse(ipath, genes, health, strands);

    cout << "  Number of genes: " << genes.size() << endl;
    cout << "  Number of strands: " << strands.size() << endl;

    auto start0 = chrono::high_resolution_clock::now();

    unsigned long long min = numeric_limits<unsigned long long>::max();
    unsigned long long max = 0;
    for (auto strand : strands) {
        int first = strand.start;
        int last = strand.end;
        string d = strand.d;
        // auto start1 = chrono::high_resolution_clock::now();
        unsigned long long val = analyze_single_strand(genes, health, first, last, d);
        // auto duration1 = chrono::high_resolution_clock::now() - start1;
        
        // cout << "  Duration: "
        //     << chrono::duration_cast<chrono::nanoseconds>(duration1).count()
        //     << " (ns)\n";
        
        min = (val < min) ? val : min;
        max = (val > max) ? val : max;
    }
    auto duration0 = chrono::high_resolution_clock::now() - start0;
    cout << "  Total: "
            << chrono::duration_cast<chrono::milliseconds>(duration0).count()
            << " (ms)\n";

    cout << min << " " << max << endl;
}

int main(void) {
    string ipaths[] = {
        "input01.txt",
        // "input02.txt",
        "input30.txt"
    };

    for (auto ipath : ipaths) {
        proceed(ipath);
    }

    return 0;
}
