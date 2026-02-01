#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int low[100005], disc[100005], timer;
bool visited[100005];
int is_bridge[100005][100005];
map<pair<int, int>, int> edge_index;

void dfs(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                is_bridge[u][v] = 1;
                is_bridge[v][u] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    timer = 0;
    for(int i=1;i<N;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_index[{min(u, v), max(u, v)}] = i-1;
    }
    memset(visited, false, sizeof(visited));
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            dfs(i, -1);
        }
    }
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        int a, b;
        cin >> a >> b;
        if(edge_index.find({min(a, b), max(a, b)}) != edge_index.end() && is_bridge[a][b]){
            cout << 1 << "\n";
        }
        else{
            cout << 2 << "\n";
        }
    }
}