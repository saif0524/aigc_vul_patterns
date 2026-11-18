#include <iostream>
#include <string>

int main() {
    ((void)0);
    ((void)0);

    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ((i > 0 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2])) {
                ++ans;
                s[i] = '.';
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}