#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            std::cout << "YES\n" << i + 1 << ' ' << i + 2 << '\n';
            return 0;
        }
    }

    for (int i = n - 1; i > 0; --i) {
        if (s[i] < s[i - 1]) {
            std::cout << "YES\n" << i << ' ' << i + 1 << '\n';
            return 0;
        }
    }

    std::cout << "NO\n";

    return 0;
}