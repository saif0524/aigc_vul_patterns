#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXM = 105;

vector<int> adj[MAXN][MAXM];
bool vis[MAXN];

void dfs(int u, int color, int n) {
    vis[u] = true;
    for (int v : adj[u][color]) {
        if (!vis[v]) {
            dfs(v, color, n);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--, c--;
        adj[u][c].push_back(v);
        adj[v][c].push_back(u);
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int ans = 0;
        for (int i = 0; i < m; i++) {
            memset(vis, 0, sizeof vis);
            dfs(u, i, n);
            if (vis[v]) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}