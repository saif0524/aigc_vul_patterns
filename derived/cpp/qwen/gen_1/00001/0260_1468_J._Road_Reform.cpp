#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long s;
};

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    x = find(x, parent);
    y = find(y, parent);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        long long k;
        cin >> n >> m >> k;
        vector<Edge> edges(m);
        for(auto &e: edges){
            cin >> e.u >> e.v >> e.s;
            e.u--; e.v--;
        }
        sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b){
            return a.s > b.s;
        });
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
        int mstEdges = 0;
        long long changes = 0;
        for(auto &e: edges){
            if(find(e.u, parent) != find(e.v, parent)){
                unite(e.u, e.v, parent, rank);
                if(e.s > k) changes += e.s - k;
                else if(e.s < k) changes += k - e.s;
                mstEdges++;
                if(mstEdges == n-1) break;
            }
        }
        cout << changes << "\n";
    }
}