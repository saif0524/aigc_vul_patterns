#include <iostream>
#include <set>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::set<std::string> distinct_strings;

    for (int i = 1; i <= s.length(); ++i) {
        for (int j = 1; j <= t.length(); ++j) {
            distinct_strings.insert(s.substr(0, i) + t.substr(0, j));
        }
    }

    std::cout << distinct_strings.size() << std::endl;

    return 0;
}