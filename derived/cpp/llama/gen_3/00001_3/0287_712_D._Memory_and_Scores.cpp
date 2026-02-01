#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int dp[101][20001];

int main() {
    int a, b, k, t;
    std::cin >> a >> b >> k >> t;

    std::vector<int> val;
    for (int i = -k; i <= k; i++) {
        val.push_back(i);
    }

    dp[0][a - b + 10000] = 1;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= 20000; j++) {
            if (dp[i - 1][j] != 0) {
                for (int v : val) {
                    int nj = j - v + k;
                    if (nj >= 0 && nj <= 20000) {
                        dp[i][nj] = add(dp[i][nj], dp[i - 1][j]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 10001; i <= 20000; i++) {
        ans = add(ans, dp[t][i]);
    }

    std::cout << ans << std::endl;

    return 0;
}