#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int MAXM = 20;

int n, m;
string s[MAXN];
int cost[MAXN][MAXM];
int dp[1 << MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        dp[mask] = 1e9;
    }
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                int newMask = mask | (1 << i);
                for (int j = 0; j < m; j++) {
                    bool unique = true;
                    for (int k = 0; k < n; k++) {
                        if (k != i && s[k][j] == s[i][j]) {
                            unique = false;
                            break;
                        }
                    }
                    if (unique) {
                        dp[newMask] = min(dp[newMask], dp[mask]);
                        break;
                    }
                }
                if (dp[newMask] == 1e9) {
                    for (int j = 0; j < m; j++) {
                        dp[newMask] = min(dp[newMask], dp[mask] + cost[i][j]);
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}