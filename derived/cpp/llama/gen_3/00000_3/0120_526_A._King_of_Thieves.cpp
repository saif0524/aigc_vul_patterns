#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    bool found = false;
    for (int step = 1; step <= n / 4; ++step) {
        for (int start = 0; start < n; ++start) {
            if (s[start] != '*') continue;
            if (start + 4 * step >= n) continue;

            if (s[start] == '*' && s[start + step] == '*' &&
                s[start + 2 * step] == '*' && s[start + 3 * step] == '*' &&
                s[start + 4 * step] == '*') {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}