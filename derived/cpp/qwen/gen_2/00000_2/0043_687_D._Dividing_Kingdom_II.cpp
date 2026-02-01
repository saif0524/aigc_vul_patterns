#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> parent, rank;
    UF(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot) {
            if (rank[xroot] < rank[yroot]) {
                parent[xroot] = yroot;
            } else if (rank[xroot] > rank[yroot]) {
                parent[yroot] = xroot;
            } else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> roads(m);
    for(auto & [u, v, w] : roads){
        cin >> u >> v >> w;
        --u, --v;
    }
    vector<int> l(q), r(q);
    for(int i = 0; i < q; ++i){
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }
    vector<vector<int>> queries(n, vector<int>(n, -1));
    for(int i = 0; i < q; ++i){
        queries[l[i]][r[i]] = i;
    }
    UF uf(n);
    vector<int> ans(q);
    for(int s = m-1; s >= 0; --s){
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(queries[i][j] != -1 && uf.find(i) == uf.find(j)){
                    ans[queries[i][j]] = get<2>(roads[s]);
                }
            }
        }
        if(s > 0){
            uf.unite(get<0>(roads[s-1]), get<1>(roads[s-1]));
        }
    }
    for(auto x : ans){
        cout << x << "\n";
    }
}