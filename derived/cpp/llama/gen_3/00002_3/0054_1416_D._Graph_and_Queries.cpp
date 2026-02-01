#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 5;
const int M = 3e5 + 5;

struct Edge {
    int u, v;
};

int n, m, q;
int p[N];
Edge edges[M];
bool used[M];
vector<int> g[N];
int ufs[N], dep[N];

void init_uf() {
    for (int i = 1; i <= n; ++i) {
        ufs[i] = i;
    }
}

int find(int x) {
    if (ufs[x] == x) return x;
    return ufs[x] = find(ufs[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    ufs[x] = y;
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].u >> edges[i].v;
    }
    init_uf();
    for (int i = 1; i <= m; ++i) {
        merge(edges[i].u, edges[i].v);
    }
    for (int i = 1; i <= m; ++i) {
        if (!used[i]) {
            g[edges[i].u].push_back(edges[i].v);
            g[edges[i].v].push_back(edges[i].u);
        }
    }
    dfs(1, 0);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int v;
            cin >> v;
            int u = v;
            while (dep[find(u)] > dep[find(v)]) {
                u = find(u);
                if (p[u]!= 0) {
                    v = u;
                    break;
                }
            }
            cout << p[v] << '\n';
            p[v] = 0;
        } else {
            int i;
            cin >> i;
            if (!used[i]) {
                used[i] = true;
                g[edges[i].u].clear();
                g[edges[i].v].clear();
                init_uf();
                for (int j = 1; j <= m; ++j) {
                    if (!used[j]) {
                        merge(edges[j].u, edges[j].v);
                    }
                }
                for (int j = 1; j <= m; ++j) {
                    if (!used[j]) {
                        g[edges[j].u].push_back(edges[j].v);
                        g[edges[j].v].push_back(edges[j].u);
                    }
                }
                dfs(1, 0);
            }
        }
    }
    return 0;
}