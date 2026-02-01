#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 1e9 + 7;

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int cnt = 0, ans = 0;
    std::vector<long long> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            dp[i + 1] = (dp[i + 1] + 1) % MOD;
            if (cnt > 0) {
                dp[i + 1] = (dp[i + 1] + dp[cnt]) % MOD;
            }
        }
        if (s[i] == 'b') {
            cnt = i + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}