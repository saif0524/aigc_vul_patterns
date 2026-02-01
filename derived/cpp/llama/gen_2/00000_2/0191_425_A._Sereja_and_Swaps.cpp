#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MIN));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (i - 1) * a[i - 1]);
            if (j > 0) {
                for (int t = 0; t < i; ++t) {
                    dp[i][j] = max(dp[i][j], dp[t][j - 1] + (i - 1) * a[t] + (t - 1) * (i - 1) * a[i - 1]);
                }
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}