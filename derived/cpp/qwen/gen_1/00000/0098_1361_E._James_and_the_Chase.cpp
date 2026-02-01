#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> indegree, outdegree;
vector<int> ts;
bool visited[100005];

void toposort(int n) {
    queue<int> q;
    for(int i = 1; i <= n; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ts.push_back(u);
        for(auto v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    for(auto v : adj[u]) {
        if(!visited[v]) dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        adj.assign(n+1, vector<int>());
        indegree.assign(n+1, 0);
        outdegree.assign(n+1, 0);
        ts.clear();
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        toposort(n);
        vector<int> interesting;
        if(ts.size() != n) {
            cout << "-1\n";
            continue;
        }
        for(int i = 1; i <= n; i++) {
            if(indegree[i] != 0 || outdegree[i] == 0) continue;
            memset(visited, false, sizeof(visited));
            dfs(i);
            int cnt = 0;
            for(int j = 1; j <= n; j++) if(visited[j]) cnt++;
            if(cnt == n) interesting.push_back(i);
        }
        if(interesting.size() < (n + 4) / 5) cout << "-1\n";
        else {
            for(int i = 0; i < interesting.size(); i++) cout << interesting[i] << " \n"[i == interesting.size() - 1];
        }
    }
    return 0;
}