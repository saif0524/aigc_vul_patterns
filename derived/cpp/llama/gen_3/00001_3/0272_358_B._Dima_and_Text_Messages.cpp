#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::string> words;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::getline(std::cin, word);
        words.push_back(word);
    }

    std::string message;
    std::getline(std::cin, message);

    std::string pattern = "<3";
    for (const auto& word : words) {
        pattern += word + "<3";
    }

    std::regex re(pattern);
    std::string result = std::regex_replace(message, re, "");

    if (result.empty()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}