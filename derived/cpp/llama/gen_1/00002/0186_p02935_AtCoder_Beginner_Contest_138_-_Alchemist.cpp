#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int INF = 1e9;

double dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = v[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = 0;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], (dp[i][k] + dp[k + 1][j]) / 2.0);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[0][n - 1] << endl;

    return 0;
}