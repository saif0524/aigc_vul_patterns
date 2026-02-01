#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            vector<vector<long long>> dp(r - l + 2, vector<long long>(s + 1, 0));
            dp[0][0] = 1;

            for (int i = 0; i < r - l + 1; ++i) {
                for (int j = 0; j <= s; ++j) {
                    if (dp[i][j] > 0) {
                        if (j + a[l + i] <= s) {
                            dp[i + 1][j + a[l + i]] = (dp[i + 1][j + a[l + i]] + dp[i][j]) % MOD;
                        }
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                    }
                }
            }

            total_sum = (total_sum + dp[r - l + 1][s]) % MOD;
        }
    }

    cout << total_sum << endl;

    return 0;
}