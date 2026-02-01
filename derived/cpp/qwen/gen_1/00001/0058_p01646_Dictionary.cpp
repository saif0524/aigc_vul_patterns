#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::string> words(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> words[i];
        }
        
        bool is_lexicographically_ordered = std::is_sorted(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a < b;
        });
        
        std::cout << (is_lexicographically_ordered ? "yes" : "no") << std::endl;
    }
    return 0;
}