#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
int par[MAXN], rank[MAXN];
int ans[MAXN];
vector<int> g[MAXN];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) par[x] = y;
    else if (rank[x] > rank[y]) par[y] = x;
    else {
        par[y] = x;
        rank[x]++;
    }
}

void dfs(int u, int p, int d) {
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        queue<pair<int, int>> q;
        q.push({u, 0});
        vector<int> vis(n + 1, 0);
        vis[u] = 1;
        int has = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int nxt : g[cur.first]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    if (nxt == v) has++;
                    else q.push({nxt, cur.second + 1});
                }
            }
        }
        cout << has << '\n';
    }

    return 0;
}