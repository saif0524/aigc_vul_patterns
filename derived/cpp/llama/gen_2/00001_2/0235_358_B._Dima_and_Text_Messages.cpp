#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> words;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }
    std::string message;
    std::cin >> message;

    std::string encodedMessage;
    for (const auto& word : words) {
        encodedMessage += "<3" + word;
    }
    encodedMessage += "<3";

    std::regex pattern("<3[^(<3)]*");
    auto matchesBegin = std::sregex_iterator(message.begin(), message.end(), pattern);
    auto matchesEnd = std::sregex_iterator();

    int matchIndex = 0;
    for (std::sregex_iterator i = matchesBegin; i != matchesEnd; ++i) {
        std::smatch match = *i;
        if (matchIndex == 0) {
            if (match.str() != "<3" + words[0]) {
                std::cout << "no" << std::endl;
                return 0;
            }
        } else if (matchIndex == words.size()) {
            if (match.str() != "<3") {
                std::cout << "no" << std::endl;
                return 0;
            }
        } else {
            if (match.str() != "<3" + words[matchIndex]) {
                std::cout << "no" << std::endl;
                return 0;
            }
        }
        matchIndex++;
    }

    if (matchIndex != words.size() + 1) {
        std::cout << "no" << std::endl;
        return 0;
    }

    std::cout << "yes" << std::endl;
    return 0;
}