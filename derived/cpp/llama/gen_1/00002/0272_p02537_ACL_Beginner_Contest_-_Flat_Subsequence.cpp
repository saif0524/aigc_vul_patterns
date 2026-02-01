#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(a[i] - a[j]) <= k) {
                dp[i][i] = max(dp[i][i], dp[j][j] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i][i]);
    }

    cout << ans << endl;

    return 0;
}