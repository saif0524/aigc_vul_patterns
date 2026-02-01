#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
const int MAXM = 25;

int n, m;
string s[MAXN];
int cost[MAXN][MAXM];
int dp[1 << MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    fill(dp, dp + (1 << n), INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) continue;
            for (int j = 0; j < m; j++) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    if (s[k][j] == s[i][j]) ok = false;
                }
                if (ok) {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask]);
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) continue;
            for (int j = 0; j < m; j++) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    if (s[k][j] == s[i][j]) ok = false;
                }
                if (!ok) {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + cost[i][j]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << '\n';

    return 0;
}