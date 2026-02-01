#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n);
    vector<int> component;
    auto dfs = [&](auto &self, int u){
        if(vis[u]) return;
        vis[u] = true;
        component.push_back(u);
        for(auto v: adj[u]){
            self(self, v);
        }
    };
    for(int i=0;i<n;i++){
        if(!vis[i]){
            component.clear();
            dfs(dfs, i);
            vector<int> vals;
            for(auto idx: component) vals.push_back(p[idx]);
            sort(vals.begin(), vals.end(), greater<int>());
            sort(component.begin(), component.end());
            for(int j=0;j<component.size();j++){
                p[component[j]] = vals[j];
            }
        }
    }
    for(auto x: p) cout << x << ' ';
}