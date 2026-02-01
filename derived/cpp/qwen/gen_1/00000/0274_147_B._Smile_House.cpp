#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        dist[u][v] = c1;
        dist[v][u] = c2;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = INF;
    for (int k = 2; k <= n; ++k) {
        vector<int> dp(1 << k, INF);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << k); ++mask) {
            int cnt = __builtin_popcount(mask);
            for (int prev = 0; prev < k; ++prev) {
                if (mask & (1 << prev)) {
                    int new_mask = mask ^ (1 << prev);
                    if (dp[new_mask] != INF) {
                        int u = (new_mask == 0 ? 1 : (prev + 1));
                        int v = cnt;
                        dp[mask] = min(dp[mask], dp[new_mask] + dist[u][v]);
                    }
                }
            }
        }
        if (dp[(1 << k) - 1] + dist[k][1] < 0) {
            ans = min(ans, k);
        }
    }
    if (ans == INF) {
        cout << 0;
    } else {
        cout << ans;
    }
}