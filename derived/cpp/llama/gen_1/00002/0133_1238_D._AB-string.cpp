#include <iostream>
#include <string>

long long countGoodSubstrings(const std::string& s) {
    int n = s.length();
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        bool foundA = false, foundB = false;
        for (int j = i; j < n; ++j) {
            if (s[j] == 'A') foundA = true;
            if (s[j] == 'B') foundB = true;

            bool good = false;
            for (int k = i; k <= j; ++k) {
                for (int len = 2; k + len - 1 <= j; ++len) {
                    std::string substr = s.substr(k, len);
                    std::string reversed = substr;
                    std::reverse(reversed.begin(), reversed.end());
                    if (substr == reversed) {
                        good = true;
                        break;
                    }
                }
                if (good) break;
            }

            if (good) ++count;
        }
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::cout << countGoodSubstrings(s) << std::endl;

    return 0;
}