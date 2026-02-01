#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.size();
        long long sum = 0;

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                std::string p = s.substr(i, len);
                int count = 0;

                for (int j = 0; j <= n - len; ++j) {
                    if (s.substr(j, len) == p) {
                        ++count;
                    }
                }

                sum += count;
            }
        }

        std::cout << sum << std::endl;
    }

    return 0;
}