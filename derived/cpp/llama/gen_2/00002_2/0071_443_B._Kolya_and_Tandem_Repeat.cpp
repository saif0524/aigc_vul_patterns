#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;

    int n = s.length();
    int ans = 0;

    for (int i = 1; i <= n + k; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (j + i < n) {
                if (s[j]!= s[j + i]) {
                    ok = false;
                    break;
                }
            } else {
                if (s[j]!= s[j + i - n]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans = i * 2;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}