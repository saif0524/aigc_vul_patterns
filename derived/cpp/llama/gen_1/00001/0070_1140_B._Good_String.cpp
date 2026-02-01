#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                std::string substr = s.substr(i, j - i + 1);
                int countGreater = 0, countLess = 0;
                for (char c : substr) {
                    if (c == '>') {
                        ++countGreater;
                    } else {
                        ++countLess;
                    }
                }
                if (countGreater == countLess + 1 || countLess == countGreater + 1 || (countGreater == 1 && countLess == 0) || (countLess == 1 && countGreater == 0)) {
                    ans = std::min(ans, n - (j - i + 1));
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}