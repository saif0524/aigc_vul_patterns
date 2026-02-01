#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

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