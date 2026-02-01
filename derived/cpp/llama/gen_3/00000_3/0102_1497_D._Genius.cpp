#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 5005;

long long dp[MAXN][MAXN];
int tag[MAXN], s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> tag[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        memset(dp, 0, sizeof(dp));
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && tag[i] != tag[j]) {
                    long long diff = abs(s[i] - s[j]);
                    dp[i][j] = diff;
                    for (int k = 1; k <= n; k++) {
                        if (k != i && k != j && tag[k] != tag[i] && abs(2 << (k - 1) - 2 << (i - 1)) > abs(2 << (j - 1) - 2 << (i - 1))) {
                            dp[i][j] = max(dp[i][j], dp[k][i] + diff);
                        }
                        if (k != i && k != j && tag[k] != tag[j] && abs(2 << (k - 1) - 2 << (j - 1)) > abs(2 << (i - 1) - 2 << (j - 1))) {
                            dp[i][j] = max(dp[i][j], dp[k][j] + diff);
                        }
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}