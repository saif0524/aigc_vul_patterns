#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> adj[MAXN];
int in_degree[MAXN];
int out_degree[MAXN];
bool visited[MAXN];

void dfs(int node, vector<int> &path) {
    visited[node] = true;
    path.push_back(node);
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next, path);
        }
    }
}

pair<int, vector<int>> findSCC(int node) {
    memset(visited, false, sizeof(visited));
    vector<int> path;
    dfs(node, path);
    memset(visited, false, sizeof(visited));
    int scc_size = 0;
    vector<int> scc;
    for (int x : path) {
        for (int next : adj[x]) {
            if (find(path.begin(), path.end(), next) != path.end()) {
                if (!visited[next]) {
                    visited[next] = true;
                    scc_size++;
                    scc.push_back(next);
                }
            }
        }
    }
    return {scc_size, scc};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            in_degree[i] = out_degree[i] = 0;
        }
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            in_degree[v]++;
            out_degree[u]++;
        }
        vector<int> interesting;
        for(int i = 1; i <= n; i++){
            if(in_degree[i] == 0){
                pair<int, vector<int>> scc = findSCC(i);
                if(scc.first == 1 && out_degree[i] == n - 1){
                    interesting.push_back(i);
                }
            }
        }
        if(interesting.size() < (n + 4) / 5){
            cout << "-1\n";
        }
        else{
            sort(interesting.begin(), interesting.end());
            for(int i = 0; i < interesting.size(); i++){
                cout << interesting[i] << " ";
            }
            cout << "\n";
        }
    }
}