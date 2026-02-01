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
    vector<bool> visited(n, false);
    function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& comp){
        if(visited[u]) return;
        visited[u] = true;
        comp.push_back(u);
        for(auto v: adj[u]){
            dfs(v, comp);
        }
    };
    vector<vector<int>> comps;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(i, comp);
            comps.push_back(comp);
        }
    }
    for(auto &comp: comps){
        vector<int> values;
        for(auto u: comp){
            values.push_back(p[u]);
        }
        sort(values.rbegin(), values.rend());
        sort(comp.begin(), comp.end());
        for(int i=0;i<comp.size();i++){
            p[comp[i]] = values[i];
        }
    }
    for(auto x: p) cout << x << " ";
    cout << "\n";
}