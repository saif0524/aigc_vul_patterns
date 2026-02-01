#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::vector<int> nums;
    std::stringstream ss(s);
    std::string token;

    while (std::getline(ss, token, '+')) {
        nums.push_back(std::stoi(token));
    }

    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i != nums.size() - 1) {
            std::cout << "+";
        }
    }

    std::cout << std::endl;

    return 0;
}