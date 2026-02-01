#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(auto &x: c) cin >> x;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> w(m, 0);
    vector<int> vis(n, 0);
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        for(auto &nxt: adj[node]){
            if(!vis[nxt]){
                w[m-(--nxt)] = c[node];
                c[nxt] -= c[node];
                dfs(nxt);
            }
        }
    };
    dfs(0);
    for(int i=0;i<n;i++) if(c[i] != 0){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(auto &x: w) cout << x << "\n";
}