#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isLexicographicallySorted(const std::vector<std::string>& words) {
    for (size_t i = 1; i < words.size(); ++i) {
        if (words[i - 1] > words[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::string> words(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> words[i];
        }
        if (isLexicographicallySorted(words)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}