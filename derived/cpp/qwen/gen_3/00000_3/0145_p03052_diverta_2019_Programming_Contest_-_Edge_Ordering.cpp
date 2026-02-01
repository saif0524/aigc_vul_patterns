#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int find(int u, vector<int>& parent) {
    if (u != parent[u]) parent[u] = find(parent[u], parent);
    return parent[u];
}

void merge(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    if (u == v) return;
    if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
}

ll kruskal(int n, vector<Edge>& edges, int exclude) {
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    sort(edges.begin(), edges.end());
    
    ll mst_weight = 0;
    int edges_used = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (i == exclude) continue;
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u, parent) != find(v, parent)) {
            merge(u, v, parent, rank);
            mst_weight += w;
            edges_used++;
        }
        if (edges_used == n - 1) break;
    }
    if (edges_used < n - 1) return 0; // Not a valid MST
    return mst_weight;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0;i < m;i++){
        cin >> edges[i].u >> edges[i].v;
        edges[i].w = i + 1;
    }
    
    ll total_sum = 0;
    
    vector<bool> essential(m, false);
    vector<int> parent(n + 1), rank(n + 1, 0);
    for(int i = 1;i <= n;i++) parent[i] = i;
    
    // Determine essential edges
    for(int i = 0;i < m;i++){
        int u = edges[i].u, v = edges[i].v;
        if(find(u, parent) != find(v, parent)){
            merge(u, v, parent, rank);
            essential[i] = true;
        }
    }
    
    do {
        bool valid = true;
        for(int i = 0;i < m;i++){
            if(essential[i] && edges[i].w != i + 1){
                valid = false;
                break;
            }
        }
        if(valid){
            total_sum += kruskal(n, edges, -1);
            total_sum %= MOD;
        }
    } while(next_permutation(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    }));
    
    cout << total_sum;
}