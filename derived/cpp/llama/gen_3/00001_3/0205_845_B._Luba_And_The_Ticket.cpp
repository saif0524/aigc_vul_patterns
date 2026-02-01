#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int ans = 3;
    for (int mask = 0; mask < (1 << 6); mask++) {
        int sum1 = 0, sum2 = 0;
        std::string t = s;
        for (int i = 0; i < 6; i++) {
            if (mask & (1 << i)) {
                t[i] = '0' + (i < 3? (sum2 - sum1) : (sum1 - sum2));
            }
            if (i < 3) sum1 += t[i] - '0';
            else sum2 += t[i] - '0';
        }
        if (sum1 == sum2) {
            int cnt = 0;
            for (int i = 0; i < 6; i++) {
                if (mask & (1 << i)) cnt++;
            }
            ans = std::min(ans, cnt);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}