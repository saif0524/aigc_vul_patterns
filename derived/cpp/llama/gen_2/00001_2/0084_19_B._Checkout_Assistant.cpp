#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(2 * n + 1, numeric_limits<long long>::max()));

    dp[0][t[0] + 1] = 0;
    dp[0][1] = c[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            if (j >= t[i] + 1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - t[i] - 1]);
            }
            if (j >= 1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + c[i]);
            }
        }
    }

    long long ans = numeric_limits<long long>::max();
    for (int i = 0; i <= 2 * n; ++i) {
        ans = min(ans, dp[n - 1][i]);
    }

    cout << ans << '\n';

    return 0;
}