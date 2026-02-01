#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
char s[MAXN];

int dp[MAXN][2];
int f[MAXN][2];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = -1e9;
        f[i][0] = f[i][1] = 1e9;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    f[0][0] = 0;
    f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            f[i][0] = min(f[i - 1][0], f[i - 1][1]) + 1;
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - 1);
            f[i][1] = min(f[i - 1][1], f[i - 1][0] - 1);
        } else if (s[i - 1] == '1') {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - 1) + 1;
            f[i][1] = min(f[i - 1][1], f[i - 1][0] - 1) + 1;
            dp[i][0] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
            f[i][0] = min(f[i - 1][1] + 1, f[i - 1][0]);
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1, dp[i - 1][0] - 1 + 1);
            f[i][0] = min(f[i - 1][0], f[i - 1][1] + 1, f[i - 1][0] - 1 + 1);
            dp[i][1] = max(dp[i - 1][0] - 1 + 1, dp[i - 1][1] + 1, dp[i - 1][1] - 1);
            f[i][1] = min(f[i - 1][0] - 1 + 1, f[i - 1][1] + 1, f[i - 1][1] - 1);
        }
    }
    printf("%d\n", max(dp[n][0], dp[n][1]));
}

int main() {
    solve();
    return 0;
}