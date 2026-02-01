#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

long long dp[105][2005][2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, k, t;
    cin >> a >> b >> k >> t;

    for (int i = -k; i <= k; ++i) {
        dp[0][a + i + 1000][b + i + 1000]++;
    }

    for (int i = 1; i < t; ++i) {
        for (int j = 0; j < 2005; ++j) {
            for (int l = 0; l < 2005; ++l) {
                for (int x = -k; x <= k; ++x) {
                    for (int y = -k; y <= k; ++y) {
                        if (j + x < 1000 || l + y < 1000) {
                            continue;
                        }
                        dp[i][j + x][l + y] = (dp[i][j + x][l + y] + dp[i - 1][j][l]) % MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = a + 1000 + 1; i < 2005; ++i) {
        for (int j = 0; j < i; ++j) {
            ans = (ans + dp[t - 1][i][j]) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}