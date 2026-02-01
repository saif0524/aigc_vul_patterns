#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
int t[100005], ans[100005], cnt[100005], dis[100005];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    cnt[u] += 1;
}

void imp(int u) {
    if (dis[u] > t[u]) {
        ans[m]++;
        dis[u] = 0;
    } else if (dis[u] == t[u]) {
        ans[m]--;
        dis[u] = 0;
    }
}

void update(int u, int p, int v) {
    if (u == 0) return;
    dis[u] += v;
    imp(u);
    update(p, adj[p][0] == u ? adj[p][1] : adj[p][0], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> t[i];
    dfs(1, 0);
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            update(x, adj[x].size() ? adj[x][0] : 0, -1);
        } else {
            update(-x, adj[-x].size() ? adj[-x][0] : 0, 1);
        }
        if (i > 1) ans[i] = ans[i - 1];
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}