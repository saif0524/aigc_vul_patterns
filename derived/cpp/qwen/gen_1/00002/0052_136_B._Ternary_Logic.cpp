#include <iostream>
#include <algorithm>
#include <string>

std::string decimalToTernary(int n) {
    if (n == 0) return "0";
    std::string ternary;
    while (n > 0) {
        ternary += std::to_string(n % 3);
        n /= 3;
    }
    return ternary;
}

int ternaryToDecimal(const std::string& ternary) {
    int decimal = 0;
    int base = 1;
    for (char digit : ternary) {
        decimal += (digit - '0') * base;
        base *= 3;
    }
    return decimal;
}

int findB(int a, int c) {
    std::string at = decimalToTernary(a);
    std::string ct = decimalToTernary(c);
    std::string bt;

    std::reverse(at.begin(), at.end());
    std::reverse(ct.begin(), ct.end());

    int maxLength = std::max(at.size(), ct.size());
    at.resize(maxLength, '0');
    ct.resize(maxLength, '0');

    for (int i = 0; i < maxLength; ++i) {
        int digitA = at[i] - '0';
        int digitC = ct[i] - '0';
        int digitB = (digitC - digitA + 3) % 3;
        bt += std::to_string(digitB);
    }

    std::reverse(bt.begin(), bt.end());
    return ternaryToDecimal(bt);
}

int main() {
    int a, c;
    std::cin >> a >> c;
    std::cout << findB(a, c) << std::endl;
    return 0;
}