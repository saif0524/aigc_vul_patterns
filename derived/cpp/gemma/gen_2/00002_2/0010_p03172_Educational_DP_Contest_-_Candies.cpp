#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x <= a[i - 1] && x <= j; ++x) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}