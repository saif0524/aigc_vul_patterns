#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 55;

int n, p;
int c[MAXN];
int dp[MAXN][MAXN][2];

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= 1; k++) {
                if (c[i] == -1) {
                    dp[i][j][0] = add(dp[i][j][0], dp[i-1][j][k]);
                    dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][k]);
                } else if (c[i] == k) {
                    dp[i][j][k] = add(dp[i][j][k], dp[i-1][j][k]);
                }
                for (int l = 1; l < i; l++) {
                    if (c[i] == -1) {
                        dp[i][j+l][0] = add(dp[i][j+l][0], dp[i-1][j][1]);
                        dp[i][j+l][1] = add(dp[i][j+l][1], dp[i-1][j][0]);
                    } else if (c[i] == 0) {
                        dp[i][j+l][0] = add(dp[i][j+l][0], dp[i-1][j][1]);
                    } else {
                        dp[i][j+l][1] = add(dp[i][j+l][1], dp[i-1][j][0]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = add(ans, dp[n][i][p]);
    }
    cout << ans << endl;
    return 0;
}