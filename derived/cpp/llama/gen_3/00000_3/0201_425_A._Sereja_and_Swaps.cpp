#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

int a[MAXN];
bool dp[MAXN][MAXN][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, false, sizeof(dp));
    dp[0][0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int x = 0; x <= k; x++) {
                if (dp[i-1][j][x]) {
                    dp[i][j][x] = true;
                    if (x < k && j < i) {
                        dp[i][j+1][x+1] = true;
                    }
                }
            }
        }
    }

    int ans = -1000000;
    for (int j = 0; j <= n; j++) {
        for (int x = 0; x <= k; x++) {
            if (dp[n][j][x]) {
                int sum = 0;
                for (int i = 1; i <= j; i++) {
                    sum += a[i];
                }
                for (int i = n; i > n-j; i--) {
                    sum += a[i];
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;

    return 0;
}