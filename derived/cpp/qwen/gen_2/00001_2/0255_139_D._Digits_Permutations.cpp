#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::string n;
    std::cin >> n;

    std::vector<int> digits;
    for (char c : n) {
        digits.push_back(c - '0');
    }

    std::sort(digits.begin(), digits.end());

    std::string a, b;
    for (int i = 0; i < digits.size(); ++i) {
        if (i % 2 == 0) {
            a += ('0' + digits[i]);
        } else {
            b += ('0' + digits[i]);
        }
    }

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    std::cout << a << "\n" << b << "\n";
}