#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> c(n + m + 1);
    for (int i = 1; i <= n + m; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + m + 1, -1e9));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n + m; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j >= l[i - 1]) {
                int cost = s[i - 1];
                int profit = c[l[i - 1]];
                if (j == l[i - 1]) {
                    profit += c[l[i - 1] + 1];
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + profit - cost);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n + m; ++i) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}