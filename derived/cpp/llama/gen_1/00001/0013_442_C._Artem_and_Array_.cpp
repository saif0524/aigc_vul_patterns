#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, a[MAXN];

long long dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = 0;
            for (int k = i; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + min(a[i], a[k + 1]));
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + min(a[j], a[k]));
            }
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}