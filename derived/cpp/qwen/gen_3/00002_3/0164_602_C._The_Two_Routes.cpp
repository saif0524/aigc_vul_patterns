#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    vector<int> dist_train(n+1, INF);
    vector<int> dist_bus(n+1, INF);
    
    queue<int> q_train, q_bus;
    q_train.push(1);
    q_bus.push(1);
    dist_train[1] = 0;
    dist_bus[1] = 0;
    
    while(!q_train.empty()){
        int u = q_train.front();
        q_train.pop();
        for(int v=1; v<=n; v++){
            if(adj[u][v] == 1 && dist_train[v] == INF){
                dist_train[v] = dist_train[u] + 1;
                q_train.push(v);
            }
        }
    }
    
    while(!q_bus.empty()){
        int u = q_bus.front();
        q_bus.pop();
        for(int v=1; v<=n; v++){
            if(adj[u][v] == 0 && dist_bus[v] == INF){
                dist_bus[v] = dist_bus[u] + 1;
                q_bus.push(v);
            }
        }
    }
    
    if(dist_train[n] == INF || dist_bus[n] == INF){
        cout << -1;
        return 0;
    }
    
    int result = INF;
    for(int i=1; i<=n; i++){
        if(dist_train[i] != INF && dist_bus[i] != INF && i != n){
            result = min(result, max(dist_train[i], dist_bus[i]));
        }
    }
    
    if(result == INF){
        cout << max(dist_train[n], dist_bus[n]);
    } else {
        cout << max(result + 1, max(dist_train[n], dist_bus[n]));
    }
}