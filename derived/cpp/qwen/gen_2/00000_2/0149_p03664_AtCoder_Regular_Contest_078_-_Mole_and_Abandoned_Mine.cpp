#include <bits/stdc++.h>
using namespace std;

const int N = 16;
vector<pair<int, int>> adj[N];
int dp[1 << N][N];
bool vis[1 << N][N];

int solve(int mask, int node) {
    if (vis[mask][node]) return dp[mask][node];
    vis[mask][node] = true;
    dp[mask][node] = 1e9;
    if (node == N-1 && mask == (1<<N)-1) return dp[mask][node] = 0;
    for(auto [nxt, cost] : adj[node]) {
        if(mask & (1 << nxt)) continue;
        dp[mask][node] = min(dp[mask][node], cost + solve(mask | (1 << nxt), nxt));
    }
    return dp[mask][node];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    memset(dp, 0, sizeof(dp));
    memset(vis, false, sizeof(vis));
    int ans = solve(1, 0);
    cout << (ans >= 1e9 ? -1 : ans) << "\n";
}