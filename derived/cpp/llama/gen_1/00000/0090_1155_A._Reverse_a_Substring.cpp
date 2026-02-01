#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    for (int i = 1; i < n; ++i) {
        if (s[i] < s[i - 1]) {
            std::cout << "YES\n";
            std::cout << i << " " << i + 1 << "\n";
            return 0;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i + 1] < s[i]) {
            int max_i = i + 1;
            for (int j = i + 2; j < n; ++j) {
                if (s[j] <= s[i]) {
                    max_i = j;
                } else {
                    break;
                }
            }
            std::cout << "YES\n";
            std::cout << i + 1 << " " << max_i + 1 << "\n";
            return 0;
        }
    }

    std::cout << "NO\n";
    return 0;
}