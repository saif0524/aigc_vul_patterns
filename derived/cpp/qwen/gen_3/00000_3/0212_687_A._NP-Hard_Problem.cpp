#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> res1, res2;
    bool used[n+1] = {false};
    for(int i=1; i<=n; i++){
        if(!used[i]){
            if(deg[i] == 0){
                cout << "-1\n";
                return 0;
            }
            if(deg[i] == 1){
                res1.push_back(i);
                used[i] = true;
                for(auto j : adj[i]){
                    if(!used[j]){
                        res2.push_back(j);
                        used[j] = true;
                    }
                }
            } else {
                cout << "-1\n";
                return 0;
            }
        }
    }
    if(res1.empty() || res2.empty()){
        cout << "-1\n";
    } else {
        cout << res1.size() << "\n";
        for(auto i : res1) cout << i << " ";
        cout << "\n";
        cout << res2.size() << "\n";
        for(auto i : res2) cout << i << " ";
        cout << "\n";
    }
}