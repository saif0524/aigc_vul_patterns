#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string password;
    std::cin >> password;

    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (auto& word : words) {
        std::cin >> word;
    }

    bool found = false;
    for (const auto& word : words) {
        if (word == password) {
            found = true;
            break;
        }
    }

    if (!found) {
        for (const auto& word1 : words) {
            for (const auto& word2 : words) {
                if (word1.back() == password[0] && word2[0] == password[1]) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    std::cout << (found ? "YES" : "NO") << std::endl;

    return 0;
}