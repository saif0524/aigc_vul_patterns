#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int N;
vector<vector<int>> G;
vector<int> sz;
vector<int> dp;

void dfs(int v, int p) {
    sz[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
    dp[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dp[v] = (1LL * dp[v] * dp[u]) % MOD;
    }
    if (sz[v] % 2 == 0) {
        dp[v] = (dp[v] * 2) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    G.resize(N);
    sz.resize(N);
    dp.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    cout << dp[0] << '\n';

    return 0;
}