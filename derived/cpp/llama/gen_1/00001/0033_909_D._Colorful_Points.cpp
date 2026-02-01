#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    int ans = 0;
    while (true) {
        std::string t = "";
        for (int i = 0; i < s.size(); ++i) {
            if ((i == 0 || s[i] == s[i - 1]) && (i == s.size() - 1 || s[i] == s[i + 1])) {
                t += s[i];
            }
        }
        if (t == s) break;
        s = t;
        ++ans;
    }

    std::cout << ans << std::endl;
    return 0;
}