#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> count(10, 0);
    for (char c : s) {
        count[c - '0']++;
    }

    int maxNumbers = count[8];
    for (int i = 0; i <= 9; ++i) {
        maxNumbers = std::min(maxNumbers, count[i]);
    }

    std::cout << maxNumbers << std::endl;

    return 0;
}