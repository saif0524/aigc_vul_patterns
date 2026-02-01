#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<pair<int, int>> adj[MAXN];
int xor_sum = 0;

int find_set(int v, vector<int> &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    xor_sum = 0;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        xor_sum ^= w;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(auto &e : adj[i]){
            if(i < e.first){
                pq.push({e.second, {i, e.first}});
            }
        }
    }
    int mst_weight = 0;
    int edges_used = 0;
    while(!pq.empty() && edges_used < n - 1){
        auto edge = pq.top();
        pq.pop();
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_set(u, parent) != find_set(v, parent)){
            union_sets(u, v, parent, rank);
            mst_weight += weight;
            edges_used++;
        }
    }
    if(edges_used < n - 1){
        for(int i=1;i<=n && edges_used < n - 1;i++){
            for(auto &e : adj[i]){
                if(i < e.first && find_set(i, parent) != find_set(e.first, parent)){
                    union_sets(i, e.first, parent, rank);
                    mst_weight += 0;
                    edges_used++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(auto &e : adj[i]){
            if(i < e.first && find_set(i, parent) == find_set(e.first, parent)){
                xor_sum ^= e.second;
            }
        }
    }
    mst_weight += xor_sum;
    cout << mst_weight;
}