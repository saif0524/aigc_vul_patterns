#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::vector<int> numbers;
    std::string num = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '+') {
            num += s[i];
        } else {
            numbers.push_back(std::stoi(num));
            num = "";
        }
    }

    numbers.push_back(std::stoi(num));

    std::sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i != numbers.size() - 1) {
            std::cout << "+";
        }
    }

    return 0;
}