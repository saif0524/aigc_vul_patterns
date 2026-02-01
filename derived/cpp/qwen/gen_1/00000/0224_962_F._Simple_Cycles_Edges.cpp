#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int parent[N], visit[N];
int timer = 0, tin[N], low[N];
set<int> result;
vector<pair<int, int>> edges;

void dfs(int v, int p = -1) {
    visit[v] = 1;
    tin[v] = low[v] = ++timer;
    parent[v] = p;
    for (auto to : adj[v]) {
        if (to == p) continue;
        if (visit[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                // Bridge
            } else if (low[to] == tin[v] && p != -1) {
                // Not a bridge, but part of a cycle
                int u = to, w = v;
                int idx = -1;
                while (u != v) {
                    auto it = find_if(edges.begin(), edges.end(), [&](const pair<int, int>& x) {
                        return (x.first == u && x.second == w) || (x.first == w && x.second == u);
                    });
                    if (it != edges.end()) {
                        idx = distance(edges.begin(), it) + 1;
                    }
                    if (idx != -1) result.insert(idx);
                    u = parent[u];
                    w = v;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            dfs(i);
        }
    }
    cout << result.size() << "\n";
    for(auto it = result.begin(); it != result.end(); it++){
        if(it != result.begin()) cout << " ";
        cout << *it;
    }
    cout << "\n";
}