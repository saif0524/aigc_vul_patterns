#include <bits/stdc++.h>
using namespace std;

struct LCA {
    vector<int> height, euler, first_occurrence;
    vector<vector<int>> sparse_table;
    int log_n, n;

    LCA(vector<vector<int>> &adj) {
        n = adj.size();
        log_n = 32 - __builtin_clz(n);
        euler = vector<int>(2 * n);
        height = vector<int>(2 * n);
        first_occurrence = vector<int>(n, -1);
        sparse_table = vector<vector<int>>(2 * n, vector<int>(log_n));
        int idx = 0;
        dfs(1, adj, idx, 0);
        preprocess();
    }

    void dfs(int u, vector<vector<int>> &adj, int &idx, int h) {
        euler[idx] = u;
        height[idx] = h;
        if (first_occurrence[u] == -1)
            first_occurrence[u] = idx;
        idx++;
        for (int v : adj[u]) {
            dfs(v, adj, idx, h + 1);
            euler[idx] = u;
            height[idx] = h;
            idx++;
        }
    }

    void preprocess() {
        int k, n = euler.size();
        for (int i = 0; i < n; i++)
            sparse_table[i][0] = i;
        for (k = 1; k < log_n; k++)
            for (int i = 0; i + (1 << k) <= n; i++) {
                int x = sparse_table[i][k - 1];
                int y = sparse_table[i + (1 << (k - 1))][k - 1];
                sparse_table[i][k] = (height[x] < height[y] ? x : y);
            }
    }

    int query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        int x = sparse_table[l][k];
        int y = sparse_table[r - (1 << k) + 1][k];
        return (height[x] < height[y] ? x : y);
    }

    int lca(int u, int v) {
        return euler[query(first_occurrence[u], first_occurrence[v])];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n + 1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca_solver(adj);
    vector<pair<int, int>> paths(m);
    for(auto &[u, v]: paths){
        cin >> u >> v;
    }
    vector<vector<int>> path_edges(m);
    for(int i=0; i<m; i++){
        int u = paths[i].first, v = paths[i].second;
        int lca_node = lca_solver.lca(u, v);
        int pu = u, pv = v;
        while(pu != lca_node){
            path_edges[i].push_back({pu, lca_node});
            pu = adj[pu][adj[pu].back() == lca_node ? adj[pu].size() - 2 : adj[pu].size() - 1];
        }
        while(pv != lca_node){
            path_edges[i].push_back({pv, lca_node});
            pv = adj[pv][adj[pv].back() == lca_node ? adj[pv].size() - 2 : adj[pv].size() - 1];
        }
        path_edges[i].push_back({u, lca_node});
        path_edges[i].push_back({v, lca_node});
    }
    map<pair<int, int>, int> edge_count;
    for(auto &edges: path_edges){
        for(auto &[u, v]: edges){
            edge_count[{min(u, v), max(u, v)}]++;
        }
    }
    long long ans = 0;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            int cnt = 0;
            for(auto &[u, v]: path_edges[i]){
                if(edge_count[{min(u, v), max(u, v)}] > 1 && edge_count[{min(u, v), max(u, v)}] == edge_count[{min(u, v), max(u, v)}, j + 1]){
                    cnt++;
                }
            }
            if(cnt >= k){
                ans++;
            }
        }
    }
    cout << ans;
}