#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::map<std::string, int> m;

    for (int i = 0; i < n - 1; i++) {
        std::string twoGram = s.substr(i, 2);
        if (m.find(twoGram) != m.end()) {
            m[twoGram]++;
        } else {
            m[twoGram] = 1;
        }
    }

    std::string maxTwoGram;
    int maxCount = 0;

    for (const auto& pair : m) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxTwoGram = pair.first;
        }
    }

    std::cout << maxTwoGram << std::endl;

    return 0;
}