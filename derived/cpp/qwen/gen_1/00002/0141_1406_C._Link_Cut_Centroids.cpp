#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> centroid;
        vector<int> sz(n+1, 0);
        function<void(int, int)> dfs = [&](int u, int p){
            sz[u] = 1;
            bool is_centroid = true;
            int max_subtree = 0;
            for(auto v : adj[u]){
                if(v == p) continue;
                dfs(v, u);
                sz[u] += sz[v];
                max_subtree = max(max_subtree, sz[v]);
                if(sz[v] > n/2) is_centroid = false;
            }
            if(n - sz[u] > n/2) is_centroid = false;
            if(is_centroid) centroid.push_back(u);
        };
        dfs(1, -1);
        int c1 = centroid[0], c2 = -1;
        if(centroid.size() == 2) c2 = centroid[1];
        int cut_edge_x, cut_edge_y;
        if(c2 != -1){
            for(auto v : adj[c1]){
                if(v == c2){
                    cut_edge_x = c1;
                    cut_edge_y = c2;
                    break;
                }
            }
        }
        else{
            for(auto v : adj[c1]){
                cut_edge_x = c1;
                cut_edge_y = v;
                break;
            }
        }
        cout << cut_edge_x << " " << cut_edge_y << "\n";
        cout << cut_edge_x << " " << cut_edge_y << "\n";
    }
}