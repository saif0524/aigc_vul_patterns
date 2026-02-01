#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main() {
    int a, c;
    std::cin >> a >> c;

    std::vector<int> aTernary;
    std::vector<int> cTernary;

    while (a > 0) {
        aTernary.push_back(a % 3);
        a /= 3;
    }

    while (c > 0) {
        cTernary.push_back(c % 3);
        c /= 3;
    }

    std::reverse(aTernary.begin(), aTernary.end());
    std::reverse(cTernary.begin(), cTernary.end());

    int maxLength = std::max(aTernary.size(), cTernary.size());

    aTernary.resize(maxLength, 0);
    cTernary.resize(maxLength, 0);

    std::vector<int> bTernary;

    for (int i = 0; i < maxLength; ++i) {
        bTernary.push_back((cTernary[i] - aTernary[i] + 3) % 3);
    }

    reverse(bTernary.begin(), bTernary.end());

    long long b = 0;
    long long power = 1;

    for (int i = 0; i < bTernary.size(); ++i) {
        b += bTernary[i] * power;
        power *= 3;
    }

    std::cout << b << std::endl;

    return 0;
}