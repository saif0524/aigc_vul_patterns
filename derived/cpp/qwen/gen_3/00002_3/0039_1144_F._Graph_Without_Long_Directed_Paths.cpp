#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    function<bool(int, int)> bipartite_check = [&](int node, int c){
        color[node] = c;
        for(int nei: adj[node]){
            if(color[nei] == -1){
                if(!bipartite_check(nei, 1-c)) return false;
            }
            else if(color[nei] == c) return false;
        }
        return true;
    };
    if(!bipartite_check(0, 0)){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(color[u] < color[v]) cout << '0';
        else cout << '1';
    }
}