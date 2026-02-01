#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) ++rank[u];
    }
    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    vector<int> edge_indices(M);
    for(int i=0;i<M;i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; edges[i].second--;
        edge_indices[i] = i;
    }
    vector<int> tree_edges(N-1);
    int index = 0;
    for(int i=0;i<M;i++){
        if(edges[i].first == 0 || edges[i].second == 0){
            tree_edges[index++] = i;
        }
    }
    ll total_sum = 0;
    do{
        UnionFind uf(N);
        ll current_sum = 0;
        for(int i=0;i<N-1;i++){
            int e = tree_edges[i];
            current_sum += edge_indices[e] + 1;
            uf.unite(edges[e].first, edges[e].second);
        }
        bool is_mst = true;
        for(int i=0;i<M;i++){
            int e = edge_indices[i];
            if(!uf.sameSet(edges[e].first, edges[e].second)){
                is_mst = false;
                break;
            }
        }
        if(is_mst){
            total_sum = (total_sum + current_sum) % MOD;
        }
    }while(next_permutation(edge_indices.begin(), edge_indices.end()));
    cout << total_sum;
}