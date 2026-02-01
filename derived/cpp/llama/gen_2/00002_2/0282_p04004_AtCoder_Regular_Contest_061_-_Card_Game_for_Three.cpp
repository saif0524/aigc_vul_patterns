#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return powmod(a, MOD - 2);
}

const int N = 3e5 + 5;

int dp[N][N][N][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 1;
    dp[0][0][0][2] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                for (int p = 0; p < 3; p++) {
                    if (i < n) {
                        dp[i + 1][j][l][0] = add(dp[i + 1][j][l][0], dp[i][j][l][p]);
                        dp[i + 1][j][l][1] = add(dp[i + 1][j][l][1], dp[i][j][l][p]);
                        dp[i + 1][j][l][2] = add(dp[i + 1][j][l][2], dp[i][j][l][p]);
                    }
                    if (j < m) {
                        dp[i][j + 1][l][0] = add(dp[i][j + 1][l][0], dp[i][j][l][p]);
                        dp[i][j + 1][l][1] = add(dp[i][j + 1][l][1], dp[i][j][l][p]);
                        dp[i][j + 1][l][2] = add(dp[i][j + 1][l][2], dp[i][j][l][p]);
                    }
                    if (l < k) {
                        dp[i][j][l + 1][0] = add(dp[i][j][l + 1][0], dp[i][j][l][p]);
                        dp[i][j][l + 1][1] = add(dp[i][j][l + 1][1], dp[i][j][l][p]);
                        dp[i][j][l + 1][2] = add(dp[i][j][l + 1][2], dp[i][j][l][p]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                ans = add(ans, dp[i][j][l][0]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}