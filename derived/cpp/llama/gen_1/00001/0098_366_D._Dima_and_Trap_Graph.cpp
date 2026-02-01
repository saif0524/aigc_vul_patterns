#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to, l, r;
};

vector<vector<Edge>> g;
int n, m;
int ans = 0;

void dfs(int v, int p, int l, int r) {
    if (v == n) {
        ans = max(ans, r - l + 1);
        return;
    }
    for (const auto& e : g[v]) {
        if (e.to == p) continue;
        int nl = max(l, e.l);
        int nr = min(r, e.r);
        if (nl <= nr) dfs(e.to, v, nl, nr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        --a; --b;
        g[a].push_back({b, l, r});
        g[b].push_back({a, l, r});
    }
    dfs(0, -1, 0, 1000000);
    if (ans == 0) cout << "Nice work, Dima!";
    else cout << ans;
    return 0;
}