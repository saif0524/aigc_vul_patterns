#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> g;
vector<int> cnt;

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int dfs2(int u, int p) {
    int res = 1;
    for (int v : g[u]) {
        if (v != p) {
            int cur = dfs2(v, u);
            if (2 * cnt[v] > n) {
                cur = (cur * 2) % MOD;
            }
            res = (res * cur) % MOD;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cnt.resize(n);
    dfs(0, -1);

    cout << dfs2(0, -1) << endl;

    return 0;
}