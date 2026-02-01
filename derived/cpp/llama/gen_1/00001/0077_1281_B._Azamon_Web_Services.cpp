#include <iostream>
#include <string>
#include <algorithm>

bool lexicographicallySmaller(const std::string& a, const std::string& b) {
    return a < b;
}

std::string swapCharacters(std::string s, int i, int j) {
    std::swap(s[i], s[j]);
    return s;
}

std::string solve(const std::string& s, const std::string& c) {
    if (lexicographicallySmaller(s, c)) {
        return s;
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            std::string swapped = swapCharacters(s, i, j);
            if (lexicographicallySmaller(swapped, c)) {
                return swapped;
            }
        }
    }

    return "---";
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s, c;
        std::cin >> s >> c;
        std::cout << solve(s, c) << std::endl;
    }

    return 0;
}