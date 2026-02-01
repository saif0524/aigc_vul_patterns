#include <iostream>
#include <string>
#include <set>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::set<std::string> uniqueStrings;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            uniqueStrings.insert(s.substr(0, i) + t.substr(0, j));
        }
    }

    std::cout << uniqueStrings.size() << std::endl;

    return 0;
}