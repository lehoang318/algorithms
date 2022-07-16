#ifndef __NUMBER_HPP__
#define __NUMBER_HPP__

#include <string>
#include <vector>

using namespace std;

namespace alg {

class Number {
public:
    Number() : minus(false) {}

    Number(const string s) {
        minus = false;

        if (!s.empty()) {
            const size_t n = s.length();
            vector<char> tmp;
            size_t first;
            size_t last;
            size_t i = 0;

            // Remove leading spaces
            while (isSeparator(s[i])) {
                i++;
            }

            first = i;

            // Remove trailing spaces
            i = n - 1;
            while (isSeparator(s[i])) {
                i--;
            }
            last = i;

            // Translate
            for (i = last; first < i; i--) {
                if (isSeparator(s[i])) {
                    continue;
                } else if (isDigit(s[i])) {
                    tmp.push_back(s[i] - '0');
                } else {
                    tmp.clear();
                    break;
                }
            }

            if (first == i) {
                if (isDigit(s[first])) {
                    tmp.push_back(s[first] - '0');
                } else if (isSign(s[first])) {
                    if (SIGN_MINUS == s[first]) {
                        minus = true;
                    }
                } else {
                    tmp.clear();
                }
            }

            if (!tmp.empty()) {
                for (auto c : tmp) {
                    if ('\0' != c ) {
                        digits.push_back(c);
                    }
                }
            }

        }
    }

    Number(const Number &other) {
        digits = other.digits;  // copy assignment
        minus = other.minus;
    }

    Number &operator=(const Number &other) {
        this->digits = other.digits;
        this->minus = other.minus;
        return *this;
    }

    // Number operator+(Number const &other) {
    //     const size_t n0 = digits.size();
    //     const size_t n1 = other.digits.size();
    //     Number res;

    //     if (isValid() && other.isValid()) {
    //         const size_t length = (n0 > n1) ? n1 : n0;
    //         int s;
    //         int r = 0;
    //         size_t i;

    //         for (i = 0; length > i; i++) {
    //             s = digits[i] + other.digits[i] + r;
    //             res.digits.push_back(s % RADIX);

    //             r = s / RADIX;
    //         }

    //         while (n0 > i) {
    //             if (0 == r) {
    //                 res.digits.push_back(digits[i]);
    //             } else {
    //                 s = digits[i] + r;
    //                 res.digits.push_back(s % RADIX);
    //                 r = s / RADIX;
    //             }

    //             i++;
    //         }

    //         while (n1 > i) {
    //             if (0 == r) {
    //                 res.digits.push_back(other.digits[i]);
    //             } else {
    //                 s = other.digits[i] + r;
    //                 res.digits.push_back(s % RADIX);
    //                 r = s / RADIX;
    //             }

    //             i++;
    //         }
    //     }

    //     return res;
    // }

    // Number operator-(Number const &other) {
    //     const size_t n0 = digits.size();
    //     const size_t n1 = other.digits.size();
    //     Number res;

    //     if (isValid() && other.isValid() && (n0 >= n1)) {
    //         const size_t length = other.digits.size();
    //         int s;
    //         int r = 0;

    //         for (size_t i = 0; length > i; i++) {
    //             s = digits[i] + other.digits[i] + r;
    //             res.digits.push_back(s % RADIX);

    //             r = s / RADIX;
    //         }
    //     }

    //     return res;
    // }

    bool operator>(const Number &other) const {
        const size_t n0 = digits.size();
        const size_t n1 = other.digits.size();

        bool res;

        if ((0 == n0) || (0 == n1)) {
            res = false;
        } else if (minus != other.minus) {
            res = other.minus;
        } else if (n0 > n1) {
            res = !minus;
        } else if (n0 == n1) {
            size_t i = n0 - 1;

            while ((0 < i) && (digits[i] == other.digits[i])) {
                i--;
            }

            if (minus) {
                res = digits[i] < other.digits[i];
            } else {
                res = digits[i] > other.digits[i];
            }
        } else {
            res = minus;
        }

        return res;
    }

    bool operator<(const Number &other) const {
        const size_t n0 = digits.size();
        const size_t n1 = other.digits.size();

        bool res;

        if ((0 == n0) || (0 == n1)) {
            res = false;
        } else if (minus != other.minus) {
            res = minus;
        } else if (n0 < n1) {
            res = !minus;
        } else if (n0 == n1) {
            size_t i = n0 - 1;

            while ((0 < i) && (digits[i] == other.digits[i])) {
                i--;
            }

            if (minus) {
                res = digits[i] > other.digits[i];
            } else {
                res = digits[i] < other.digits[i];
            }
        } else {
            res = minus;
        }

        return res;
    }

    bool operator==(const Number &other) const {
        const size_t n0 = digits.size();
        const size_t n1 = other.digits.size();

        bool res;

        if ((0 == n0) || (0 == n1)) {
            res = false;
        } else if (minus == other.minus) {
            size_t i = n0 - 1;

            while ((0 < i) && (digits[i] == other.digits[i])) {
                i--;
            }

            res = (digits[i] == other.digits[i]);
        } else {
            res = false;
        }

        return res;
    }

    bool operator>=(const Number &other) const {
        bool res;
        if (isValid() && other.isValid()) {
            res = !((*this) < other);
        } else {
            res = false;
        }

        return res;
    }

    bool operator<=(const Number &other) const {
        bool res;
        if (isValid() && other.isValid()) {
            res = !((*this) > other);
        } else {
            res = false;
        }

        return res;
    }

    size_t length() const {
        return digits.size();
    }

    void invalidate() {
        digits.clear();
    }

    bool isValid() const {
        return !digits.empty();
    }

    string toString() const {
        const size_t n = digits.size();
        string s("");

        if (0 < n) {
            s += minus ? "-" : "+";

            size_t i = n - 1;

            while (0 < i) {
                s += digits[i--] + '0';
            }

            s += digits[0] + '0';
        } else {
            s = "Invalid";
        }

        return s;
    }

private:
    static bool isDigit(char c) {
        return ('9' >= c) && ('0' <= c);
    }

    static bool isSign(char c) {
        return (('+' == c) || ('-' == c));
    }

    static bool isSeparator(char c) {
        return ('\t' == c) || (' ' == c);
    }

    vector<char> digits;
    bool minus;

    static constexpr int RADIX = 10;
    static constexpr char SIGN_MINUS = '-';
};  // class Number

}   // namespace alg

#endif // __NUMBER_HPP__
