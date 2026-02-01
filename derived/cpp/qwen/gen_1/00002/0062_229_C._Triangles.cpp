#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n+1, 0);
    vector<unordered_set<int>> adj(n+1);
    long long total_triangles = (long long)n * (n-1) * (n-2) / 6LL;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        adj[u].insert(v);
        deg[u]++;
        deg[v]++;
    }
    long long alice_triangles = 0;
    for(int u=1; u<=n; u++){
        for(auto v: adj[u]){
            for(auto w: adj[v]){
                if(w > u && adj[u].find(w) != adj[u].end()){
                    alice_triangles++;
                }
            }
        }
    }
    alice_triangles /= 3;
    cout << alice_triangles + (total_triangles - alice_triangles) << "\n";
}