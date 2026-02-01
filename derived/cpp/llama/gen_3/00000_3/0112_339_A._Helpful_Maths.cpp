#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> nums;
    std::string temp = "";
    for (char c : input) {
        if (c == '+') {
            nums.push_back(std::stoi(temp));
            temp = "";
        } else {
            temp += c;
        }
    }
    nums.push_back(std::stoi(temp));

    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << "+";
        }
    }
    std::cout << std::endl;

    return 0;
}