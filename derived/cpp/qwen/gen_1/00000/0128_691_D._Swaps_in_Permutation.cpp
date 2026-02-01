#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> p(n);
    for (int &x : p) cin >> x;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n);
    vector<vector<int>> components;
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        components.back().push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
    };
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components.emplace_back();
            dfs(i);
        }
    }
    
    for (auto &comp : components) {
        vector<int> values;
        for (int v : comp) {
            values.push_back(p[v]);
        }
        sort(values.rbegin(), values.rend());
        sort(comp.begin(), comp.end(), [&](int x, int y) { return p[x] > p[y]; });
        for (int i = 0; i < comp.size(); ++i) {
            p[comp[i]] = values[i];
        }
    }
    
    for (int x : p) cout << x << ' ';
    cout << '\n';
    
    return 0;
}