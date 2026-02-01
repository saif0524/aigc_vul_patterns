#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
vector<pair<int, int>> adj[N];
int depth[N], par[N], val[N];
int n;

void dfs(int u, int p) {
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        val[v] = val[u] ^ e.second;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].emplace_back(v, t);
        adj[v].emplace_back(u, t);
    }

    dfs(1, 1);

    int q;
    cin >> q;

    for (int i = 1; i <= q; ++i) {
        int id;
        cin >> id;

        for (int u = 1; u <= n; ++u) {
            for (auto& e : adj[u]) {
                if (e.first == par[u] && e.second == (id == e.second)) {
                    e.second = 1 - e.second;
                }
            }
        }

        dfs(1, 1);

        int ans = 0;

        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (val[u] == val[v]) {
                    ans = max(ans, depth[u] + depth[v]);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}