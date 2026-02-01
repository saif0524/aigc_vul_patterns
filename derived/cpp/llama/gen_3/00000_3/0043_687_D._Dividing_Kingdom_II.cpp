#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const int MAX_N = 1005;
const long long INF = 1e18;

vector<pair<int, int>> g[MAX_N];
long long max_len[MAX_N][MAX_N];

void dfs(int u, int l, int r, int c, long long& max_w) {
    max_len[u][c] = max_len[u][c - 1];
    for (auto& e : g[u]) {
        int v = e.first;
        long long w = e.second;
        if (w >= l && w <= r) {
            if (max_len[v][c - 1] != -1) {
                max_len[u][c] = max(max_len[u][c], w);
            }
            if (max_len[u][c - 1] == -1) {
                dfs(v, l, r, c, max_w);
                max_len[u][c] = max(max_len[u][c], max_len[v][c]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; ++i) {
        max_len[i][0] = -1;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            max_len[j][i] = -1;
        }
        for (int j = 1; j <= n; ++j) {
            long long max_w = -1;
            dfs(j, i, i, i, max_w);
        }
    }

    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        long long ans = -1;
        for (int j = l; j <= r; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (max_len[k][r] < max_len[k][l - 1] && max_len[k][l - 1] >= 0) {
                    ans = max(ans, max_len[k][l - 1]);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}