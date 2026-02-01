#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, cnt, sz[N], rt, mx;
vector<int> g[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    if (sz[u] > mx) {
        mx = sz[u];
        rt = u;
    }
}

void dfs2(int u, int fa, int val) {
    for (int v : g[u]) {
        if (v == fa) continue;
        cout << u << " " << v << " " << val << endl;
        dfs2(v, u, val * 3);
        val++;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(rt, 0, 1);
    return 0;
}