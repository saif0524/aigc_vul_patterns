#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::unordered_map<std::string, int> freq;
    for (int i = 0; i < n - 1; ++i) {
        std::string two_gram = s.substr(i, 2);
        freq[two_gram]++;
    }
    std::string result;
    int max_count = 0;
    for (const auto& pair : freq) {
        if (pair.second > max_count) {
            max_count = pair.second;
            result = pair.first;
        }
    }
    std::cout << result << std::endl;
}