#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<tuple<int, int, int>> paths;
    vector<bool> used(m, false);
    vector<int> degree(n, 0);
    for(int i = 0; i < n; i++){
        degree[i] = adj[i].size();
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(degree[i] == 1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(degree[u] == 0) continue;
        for(int v : adj[u]){
            if(degree[v] >= 2){
                degree[v]--;
                degree[u]--;
                for(int j = 0; j < adj[v].size(); j++){
                    if(adj[v][j] == u){
                        int id = j;
                        if(id % 2 == 0 && id + 1 < adj[v].size()){
                            paths.push_back({v+1, u+1, adj[v][id+1]+1});
                            used[id] = true;
                            used[id+1] = true;
                        } else if(id % 2 == 1){
                            paths.push_back({adj[v][id-1]+1, u+1, v+1});
                            used[id] = true;
                            used[id-1] = true;
                        }
                        adj[v].erase(adj[v].begin() + j);
                        break;
                    }
                }
                if(degree[v] == 1){
                    q.push(v);
                }
            }
        }
    }
    if(paths.size() != m / 2){
        printf("No solution\n");
    } else {
        for(auto [x, y, z] : paths){
            printf("%d %d %d\n", x, y, z);
        }
    }
}