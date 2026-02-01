#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;

int n, q;
vector<int> G[MAXN];

int fa[MAXN][20], depth[MAXN];

void dfs(int u, int f) {
    for (int i = 1; i <= 19; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v == f) continue;
        fa[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (depth[fa[u][i]] >= depth[v]) u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dis(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1, 0);

    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        int d1 = dis(a, b);
        if (d1 <= k) {
            cout << "YES\n";
            continue;
        }

        int d2 = dis(a, x) + dis(y, b) - 1;
        if (d2 < 0) d2 = -d2;
        int d3 = dis(a, y) + dis(x, b) - 1;
        if (d3 < 0) d3 = -d3;

        int d4 = dis(x, y);
        if (d4 == 1) {
            if (d1 == k) {
                cout << "YES\n";
                continue;
            } else {
                cout << "NO\n";
                continue;
            }
        }

        if (k >= d4 && (k - d4) % 2 == 0) {
            cout << "YES\n";
        } else if ((d2 <= k && (k - d2) % 2 == 0) || (d3 <= k && (k - d3) % 2 == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}