#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int x, int y) { p[find(y)] = find(x); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    int total_xor = 0;
    for(auto &[u, v, w] : edges){
        cin >> u >> v >> w;
        --u, --v;
        total_xor ^= w;
    }
    sort(begin(edges), end(edges), [&](auto &a, auto &b){
        return get<2>(a) < get<2>(b);
    });
    DSU dsu(n);
    int mst_weight = 0;
    for(auto [u, v, w] : edges){
        if(dsu.find(u) != dsu.find(v)){
            dsu.unite(u, v);
            mst_weight += w;
            total_xor ^= w;
        }
    }
    for(int w = 0; w < (1 << 30) && total_xor; ++w){
        if(total_xor ^ w == 0){
            mst_weight = min(mst_weight, w);
        }
    }
    cout << mst_weight;
}