#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 110;
const int MAXR = 10100;

int n, r;
int f[MAXN], s[MAXN], p[MAXN];
double dp[MAXN][MAXR];

void solve() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> f[i] >> s[i] >> p[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= r; j++) {
            dp[i][j] = 1e18;
        }
    }

    dp[0][0] = 0.0;

    for (int i = 1; i <= n; i++) {
        double q = 1.0 - p[i] / 100.0;
        for (int j = 0; j <= r; j++) {
            if (j + f[i] <= r) {
                dp[i][j + f[i]] = min(dp[i][j + f[i]], dp[i - 1][j] + f[i]);
            }
            if (j + s[i] <= r) {
                dp[i][j + s[i]] = min(dp[i][j + s[i]], dp[i - 1][j] + s[i]);
            }
            if (i < n) {
                dp[i][j] = min(dp[i][j], (dp[i - 1][j] * q + dp[i][j]) / (q + 1.0));
            }
        }
    }

    double ans = 1e18;
    for (int i = 0; i <= r; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << fixed << setprecision(9) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}