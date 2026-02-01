#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const long long MOD = 998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    int tiles = 1;
    std::vector<long long> dp(1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            std::vector<long long> newDp(tiles + 1, 0);
            for (int k = 0; k < tiles; k++) {
                newDp[k] += dp[k];
                newDp[k] %= MOD;
                newDp[k + 1] += dp[k];
                newDp[k + 1] %= MOD;
            }
            dp = newDp;
            tiles++;
        }
        for (int j = 0; j < b[i]; j++) {
            std::vector<long long> newDp(tiles - 1, 0);
            newDp[0] += dp[0];
            newDp[0] %= MOD;
            for (int k = 1; k < tiles - 1; k++) {
                newDp[k] += dp[k - 1] + dp[k];
                newDp[k] %= MOD;
            }
            newDp[tiles - 2] += dp[tiles - 2] + dp[tiles - 1];
            newDp[tiles - 2] %= MOD;
            dp = newDp;
            tiles--;
        }
    }

    long long sum = 0;
    for (int i = 0; i < tiles; i++) {
        sum += dp[i];
        sum %= MOD;
    }
    std::cout << sum << std::endl;

    return 0;
}