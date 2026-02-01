#include <iostream>
#include <string>
#include <algorithm>

std::string toTernary(int num) {
    if (num == 0) return "0";
    std::string ternary = "";
    while (num > 0) {
        ternary += (num % 3) + '0';
        num /= 3;
    }
    std::reverse(ternary.begin(), ternary.end());
    return ternary;
}

int fromTernary(const std::string& ternary) {
    int num = 0;
    for (char c : ternary) {
        num = num * 3 + (c - '0');
    }
    return num;
}

int main() {
    int a, c;
    std::cin >> a >> c;
    std::string aTernary = toTernary(a);
    std::string cTernary = toTernary(c);
    int maxLength = std::max(aTernary.size(), cTernary.size());
    aTernary = std::string(maxLength - aTernary.size(), '0') + aTernary;
    cTernary = std::string(maxLength - cTernary.size(), '0') + cTernary;
    std::string bTernary = "";
    for (int i = 0; i < maxLength; ++i) {
        int digitA = aTernary[i] - '0';
        int digitC = cTernary[i] - '0';
        int digitB = (digitC - digitA + 3) % 3;
        bTernary += digitB + '0';
    }
    int b = fromTernary(bTernary);
    std::cout << b;
    return 0;
}