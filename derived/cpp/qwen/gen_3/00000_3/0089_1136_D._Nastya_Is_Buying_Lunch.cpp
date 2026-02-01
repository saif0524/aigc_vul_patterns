#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
vector<int> adj[N];
int pos[N], visited[N];

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = 1;
    int ans = 0;
    for (int v : adj[u]) {
        if (pos[u] < pos[v]) {
            ans = max(ans, 1 + dfs(v));
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> pos[i];
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(pos[n]);
}