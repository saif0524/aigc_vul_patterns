#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;

vector<int> adj[MAXN];
int in_degree[MAXN];
int n, m, s;
int visited[MAXN];
int dp[MAXN];
stack<int> topo;
int cycle_start = -1;
int cycle_end = -1;

void dfs(int v, int parent) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (u == parent) continue;
        if (visited[u] == 0) {
            dfs(u, v);
        } else if (visited[u] == 1) {
            cycle_start = u;
            cycle_end = v;
        }
    }
    visited[v] = 2;
    topo.push(v);
}

bool has_cycle() {
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, -1);
        }
    }
    return cycle_start != -1;
}

void find_cycle() {
    stack<int> path;
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        path.push(v);
    }
    path.push(cycle_start);
    path.push(cycle_end);
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int c;
        cin >> c;
        for(int j=1;j<=c;j++){
            int u;
            cin >> u;
            adj[i].push_back(u);
            in_degree[u]++;
        }
    }
    cin >> s;
    
    if(has_cycle()){
        cout << "Draw" << endl;
        return 0;
    }
    
    memset(dp, -1, sizeof dp);
    
    function<int(int)> dfs_dp = [&](int v) {
        if(dp[v] != -1) return dp[v];
        dp[v] = 0;
        for(int u : adj[v]){
            dp[v] = max(dp[v], 1 + dfs_dp(u));
        }
        return dp[v];
    };
    
    int max_len = dfs_dp(s);
    if(max_len >= 1e6){
        cout << "Draw" << endl;
        return 0;
    }
    
    int cur = s;
    vector<int> path;
    path.push_back(cur);
    while(true){
        bool found = false;
        for(int u : adj[cur]){
            if(dp[u] == dp[cur] - 1){
                cur = u;
                path.push_back(cur);
                found = true;
                break;
            }
        }
        if(!found) break;
    }
    
    if(dp[cur] == 0){
        cout << "Win" << endl;
        for(int x : path) cout << x << " ";
        cout << endl;
    } else {
        cout << "Draw" << endl;
    }
}