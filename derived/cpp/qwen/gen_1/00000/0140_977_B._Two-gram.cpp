#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    std::unordered_map<std::string, int> twoGramCount;
    for (int i = 0; i < n - 1; ++i) {
        std::string twoGram = s.substr(i, 2);
        twoGramCount[twoGram]++;
    }
    
    std::string mostFrequentTwoGram;
    int maxCount = 0;
    for (const auto& pair : twoGramCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentTwoGram = pair.first;
        }
    }
    
    std::cout << mostFrequentTwoGram << std::endl;
    return 0;
}