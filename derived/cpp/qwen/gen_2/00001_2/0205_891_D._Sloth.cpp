#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, dp[N][2], sub[N];
vector<int> adj[N];

void dfs1(int u, int p) {
    dp[u][0] = 1;
    sub[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sub[u] += sub[v];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}

void dfs2(int u, int p, int val) {
    dp[u][1] = val;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, max(dp[u][0] - max(dp[v][0], dp[v][1]), dp[u][1]) + max(dp[v][0], dp[v][1]));
    }
}

long long ans = 0;

void dfs3(int u, int p) {
    ans += max(dp[u][0], dp[u][1]);
    for (int v : adj[u]) {
        if (v == p) continue;
        if (sub[v] == 1) continue;
        int old_dp_u0 = dp[u][0], old_dp_u1 = dp[u][1];
        dp[u][0] -= max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[u][0] - max(dp[v][0], dp[v][1]);
        int old_dp_v0 = dp[v][0], old_dp_v1 = dp[v][1];
        dp[v][0] = max(dp[u][0], dp[u][1]) + sub[u] - sub[v];
        dp[v][1] = max(dp[v][0], dp[v][1]);
        dfs3(v, u);
        dp[u][0] = old_dp_u0;
        dp[u][1] = old_dp_u1;
        dp[v][0] = old_dp_v0;
        dp[v][1] = old_dp_v1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1, 0);
    dfs3(1, -1);
    cout << ans * 2;
}