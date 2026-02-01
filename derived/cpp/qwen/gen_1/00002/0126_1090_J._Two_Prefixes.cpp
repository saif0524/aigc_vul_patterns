#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::unordered_set<std::string> distinctConcatenations;

    for (size_t i = 1; i <= s.size(); ++i) {
        for (size_t j = 1; j <= t.size(); ++j) {
            distinctConcatenations.insert(s.substr(0, i) + t.substr(0, j));
        }
    }

    std::cout << distinctConcatenations.size() << std::endl;
    return 0;
}