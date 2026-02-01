#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<tuple<int,int,int>> paths;
    for(int i=1;i<=n;i++){
        while(adj[i].size()>=2){
            int x = adj[i].back();
            adj[i].pop_back();
            int y = i;
            int z = adj[x].back();
            adj[x].pop_back();
            for(int j=0;j<adj[x].size();j++){
                if(adj[x][j]==y){
                    swap(adj[x][j], adj[x].back());
                    adj[x].pop_back();
                    break;
                }
            }
            for(int j=0;j<adj[z].size();j++){
                if(adj[z][j]==y){
                    swap(adj[z][j], adj[z].back());
                    adj[z].pop_back();
                    break;
                }
            }
            paths.emplace_back(x, y, z);
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()!=0){
            cout << "No solution";
            return 0;
        }
    }
    for(auto [x, y, z]: paths){
        cout << x << " " << y << " " << z << "\n";
    }
}