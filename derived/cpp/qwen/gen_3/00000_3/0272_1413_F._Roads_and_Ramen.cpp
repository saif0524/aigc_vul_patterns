#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[500001];
int dp[500001][2];
bool visited[500001];
int toggle[500001];

void dfs(int u, int p) {
    visited[u] = true;
    dp[u][0] = dp[u][1] = 0;
    for (auto [v, e] : adj[u]) {
        if (visited[v] || toggle[e] == 1) continue;
        dfs(v, u);
        int t = (toggle[e] ^ 1);
        int add = dp[v][t] + 1;
        if (add > dp[u][0]) {
            dp[u][1] = dp[u][0];
            dp[u][0] = add;
        } else if (add > dp[u][1]) {
            dp[u][1] = add;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    int m;
    cin >> m;
    vector<int> queries(m);
    for(int i=0;i<m;i++){
        cin >> queries[i];
    }
    dfs(1, -1);
    int ans = dp[1][0] + dp[1][1];
    for(int i=0;i<m;i++){
        int e = queries[i];
        toggle[e] ^= 1;
        int u = 0, v = 0;
        for(auto [x, id] : adj[1]){
            if(id == e){
                u = x;
                break;
            }
        }
        for(auto [x, id] : adj[u]){
            if(id == e){
                v = x;
                break;
            }
        }
        memset(visited, 0, sizeof(visited));
        dfs(u, v);
        int cur = dp[u][0] + dp[u][1];
        dfs(v, u);
        cur = max(cur, dp[v][0] + dp[v][1]);
        ans = cur;
        cout << ans << "\n";
    }
}