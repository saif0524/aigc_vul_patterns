#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

vector<int> adj[N];
int deg[N];
int d[N];
bool vis[N];
vector<pair<int, int>> edges;
vector<int> result;

void dfs(int u, int p) {
    if (deg[u] % 2!= d[u] && d[u] != -1) {
        if (p != -1) {
            result.push_back(edges[p].second);
            deg[u]++;
            deg[edges[p].first]++;
        } else {
            cout << -1 << endl;
            exit(0);
        }
    }
    vis[u] = true;
    for (auto& v : adj[u]) {
        if (!vis[v.first]) {
            dfs(v.first, v.second);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges.push_back({u, v});
    }
    dfs(1, -1);
    for(int i=1;i<=n;i++){
        if(deg[i] % 2!= d[i] && d[i] != -1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << result.size() << endl;
    for(auto& e : result){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}