#include <iostream>
#include <string>

const int MOD = 1e9 + 7;

int main() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    long long dp[n + 1][2] = {};

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            dp[i + 1][0] = (dp[i][0] + 1) % MOD;
            dp[i + 1][1] = (dp[i][1] + dp[i][0]) % MOD;
        } else if (s[i] == 'b') {
            dp[i + 1][1] = (dp[i][1] + dp[i][0]) % MOD;
        } else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][1]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}