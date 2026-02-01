#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::unordered_set<std::string> uniqueConcatenations;

    for (size_t i = 1; i <= s.size(); ++i) {
        for (size_t j = 1; j <= t.size(); ++j) {
            uniqueConcatenations.insert(s.substr(0, i) + t.substr(0, j));
        }
    }

    std::cout << uniqueConcatenations.size() << '\n';
    return 0;
}