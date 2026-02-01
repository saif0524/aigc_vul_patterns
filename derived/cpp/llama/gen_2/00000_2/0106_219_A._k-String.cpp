#include <iostream>
#include <map>
#include <string>

int main() {
    int k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    std::map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    std::string sub;
    for (auto& pair : charCount) {
        if (pair.second % k != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        sub += std::string(pair.second / k, pair.first);
    }

    for (int i = 0; i < k; i++) {
        std::cout << sub;
    }
    std::cout << std::endl;

    return 0;
}