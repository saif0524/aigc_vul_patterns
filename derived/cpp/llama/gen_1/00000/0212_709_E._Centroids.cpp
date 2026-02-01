#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;

int n;
vector<int> g[MAXN];

int sz[MAXN];

void dfs1(int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) if (u != p) {
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

bool can[MAXN];

vector<int> order;

void dfs2(int v, int p) {
    order.push_back(v);
    for (int u : g[v]) if (u != p) {
        dfs2(u, v);
    }
}

int root_custom(int v) {
    dfs1(v, 0);
    for (int u : g[v]) if (u != 0) {
        if (sz[u] * 2 >= n) {
            return root_custom(u);
        }
    }
    return v;
}

void solve(int v) {
    dfs1(v, 0);
    order.clear();
    dfs2(v, 0);
    for (int u : order) {
        bool f = true;
        for (int to : g[u]) if (to != v) {
            if (sz[to] * 2 > n) {
                f = false;
                break;
            }
        }
        if (f) can[u] = true;
        if ((n - sz[u]) * 2 > n) f = false;
        if (f) can[v] = true;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    for (int v = 0; v < n; v++) {
        solve(v);
    }

    for (int v = 0; v < n; v++) {
        printf("%d ", can[v]);
    }
    puts("");

    return 0;
}