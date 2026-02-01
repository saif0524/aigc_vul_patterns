#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::map<std::string, int> count;
    for (int i = 0; i < n - 1; ++i) {
        std::string twoGram = s.substr(i, 2);
        ++count[twoGram];
    }

    std::string maxTwoGram;
    int maxCount = 0;
    for (const auto& pair : count) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxTwoGram = pair.first;
        }
    }

    std::cout << maxTwoGram << std::endl;

    return 0;
}