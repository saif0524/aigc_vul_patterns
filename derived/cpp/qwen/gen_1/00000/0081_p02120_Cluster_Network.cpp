#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> parent, size, weight;
    dsu(int n) : parent(n), size(n, 1), weight(n) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int v) {
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        weight[u] += weight[v];
    }
    int get_weight(int v) {
        return weight[find(v)];
    }
    void set_weight(int v, int w) {
        weight[v] = w;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> W(N);
    for(int& w : W) cin >> w;
    vector<pair<int, int>> E(M);
    for(auto& [u, v] : E){
        cin >> u >> v;
        u--; v--;
    }
    dsu d(N);
    for(int i = 0; i < N; i++) d.set_weight(i, W[i]);
    for(auto [u, v] : E) d.unite(u, v);
    vector<int> ans(N);
    vector<bool> removed(N);
    for(int i = N-1; i > 0; i--){
        int u = i;
        removed[u] = true;
        ans[i] = 0;
        for(auto [v, _] : E){
            if(v == u || removed[v]) continue;
            if(d.find(u) != d.find(v)) d.unite(u, v);
        }
        ans[i] = d.get_weight(d.find(u));
    }
    ans[0] = 0;
    for(int i = 1; i < N; i++){
        ans[0] += W[i];
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }
}