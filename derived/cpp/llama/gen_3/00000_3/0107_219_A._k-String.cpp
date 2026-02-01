#include <iostream>
#include <string>
#include <map>

int main() {
    int k;
    std::string s;

    std::cin >> k >> s;

    std::map<char, int> charCount;

    for (char c : s) {
        if (charCount.find(c) != charCount.end()) {
            charCount[c]++;
        } else {
            charCount[c] = 1;
        }
    }

    std::string baseStr;
    for (const auto& pair : charCount) {
        if (pair.second % k != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        for (int i = 0; i < pair.second / k; i++) {
            baseStr += pair.first;
        }
    }

    for (int i = 0; i < k; i++) {
        std::cout << baseStr;
    }

    std::cout << std::endl;

    return 0;
}