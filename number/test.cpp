#include <iostream>

#include "Number.hpp"

using namespace std;

void compare(const alg::Number &n0, const alg::Number &n1) {
    cout << n0.toString() << " < " << n1.toString() << "? ";
    cout << ((n0 < n1) ? "TRUE" : "FALSE") << endl;

    cout << n0.toString() << " <= " << n1.toString() << "? ";
    cout << ((n0 <= n1) ? "TRUE" : "FALSE") << endl;

    cout << n0.toString() << " == " << n1.toString() << "? ";
    cout << ((n0 == n1) ? "TRUE" : "FALSE") << endl;

    cout << n0.toString() << " >= " << n1.toString() << "? ";
    cout << ((n0 >= n1) ? "TRUE" : "FALSE") << endl;

    cout << n0.toString() << " > " << n1.toString() << "? ";
    cout << ((n0 > n1) ? "TRUE" : "FALSE") << endl;
}

int main(void) {
    vector<alg::Number> numbers = {
        alg::Number("123"),
        alg::Number("-133"),
        alg::Number("+133"),
        alg::Number("-0223"),
        alg::Number("+0223"),
        alg::Number(" 01234  "),
        alg::Number(" 01234"),
        alg::Number("01234  "),
        alg::Number("012 34  "),
        alg::Number("0123 4"),
        alg::Number("012A5")
    };
    
    for (auto number : numbers) {
        cout << number.toString() << endl;
    }
    
    compare(numbers[0], numbers[1]);
    compare(numbers[0], numbers[2]);
    compare(numbers[0], numbers[10]);
    compare(numbers[3], numbers[1]);
    compare(numbers[3], numbers[5]);
    compare(numbers[3], numbers[10]);

    return 0;
}
