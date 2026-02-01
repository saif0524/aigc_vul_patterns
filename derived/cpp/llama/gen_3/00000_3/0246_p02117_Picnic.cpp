#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;
const int MAXK = 305;
const int MAXM = 10005;
const int INF = 1e9;

int n, x, y;
int k[MAXN];
int a[MAXN][MAXK], b[MAXN][MAXK], c[MAXN][MAXK];
int d[MAXN][MAXN];

int dp[MAXN][MAXM][MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;

    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            cin >> a[i][j] >> b[i][j] >> c[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            for (int k = 0; k < MAXM; ++k) {
                dp[i][j][k] = -INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            for (int k = 0; k < MAXM; ++k) {
                if (dp[i][j][k] == -INF) continue;

                if (i == 0 && j + d[0][0] <= x && k <= y) {
                    dp[0][j + d[0][0]][k] = max(dp[0][j + d[0][0]][k], dp[i][j][k]);
                }

                for (int t = 1; t < n; ++t) {
                    if (j + d[i][t] <= x) {
                        dp[t][j + d[i][t]][k] = max(dp[t][j + d[i][t]][k], dp[i][j][k]);
                    }
                }

                for (int t = 0; t < k[i]; ++t) {
                    for (int cnt = 1; cnt <= c[i][t]; ++cnt) {
                        if (j + a[i][t] * cnt <= x && k + a[i][t] * cnt <= y) {
                            dp[i][j + a[i][t] * cnt][k + a[i][t] * cnt] = max(dp[i][j + a[i][t] * cnt][k + a[i][t] * cnt], dp[i][j][k] + b[i][t] * cnt);
                        }
                    }
                }
            }
        }
    }

    int ans = -INF;

    for (int i = 0; i < MAXM; ++i) {
        ans = max(ans, dp[0][i][y]);
    }

    cout << ans << '\n';

    return 0;
}