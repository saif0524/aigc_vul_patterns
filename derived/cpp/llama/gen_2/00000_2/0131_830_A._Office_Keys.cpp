#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= k; j++) {
            for (int l = j - 1; l >= i - 1; l--) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][l], abs(a[i - 1] - b[j - 1]) + abs(b[j - 1] - p)));
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}