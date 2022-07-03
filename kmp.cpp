// Ref: https://www.geeksforgeeks.org/

#include <iostream>
#include <string>
#include <vector>

static inline void computeLPSArray(const std::string &pattern, const size_t M, std::vector<size_t> &lps);

// Prints occurrences of text[] in pattern[]
int KMPSearch(const std::string &text, const std::string &pattern) {
    int count = 0;
    const size_t M = pattern.length();
    const size_t N = text.length();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    std::vector<size_t> lps(M, 0);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, M, lps);

    size_t i = 0; // index for text[]
    size_t j = 0; // index for pattern[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            // Match all characters
            count++;
            j = lps[j - 1];
        } else if ((N > i) && pattern[j] != text[i]) {
            // Mismatch after j matches
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return count;
}

// Fills lps[] for given patttern pattern[0..M-1]
static inline  void computeLPSArray(const std::string &pattern, const size_t M, std::vector<size_t> &lps) {
    // length of the previous longest prefix suffix
    size_t len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    size_t i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            // (pattern[i] != pattern[len])
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment i here
            } else {
                // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}
