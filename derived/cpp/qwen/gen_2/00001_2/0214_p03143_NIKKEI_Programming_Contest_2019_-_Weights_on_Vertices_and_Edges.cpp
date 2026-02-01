#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int u, v;
    ll weight;
    int index;
};

struct Node {
    ll weight;
    int parent;
    int rank;
};

int find(int u, vector<Node>& dsu) {
    while (u != dsu[u].parent) {
        dsu[u].parent = dsu[dsu[u].parent].parent;
        u = dsu[u].parent;
    }
    return u;
}

void unite(int u, int v, vector<Node>& dsu) {
    u = find(u, dsu);
    v = find(v, dsu);
    if (u == v) return;
    if (dsu[u].rank < dsu[v].rank) swap(u, v);
    dsu[v].parent = u;
    dsu[u].weight += dsu[v].weight;
    if (dsu[u].rank == dsu[v].rank) dsu[u].rank++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<ll> X(N+1);
    for(int i=1;i<=N;i++) cin >> X[i];
    vector<Edge> edges(M);
    for(int i=0;i<M;i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].index = i;
    }
    vector<Node> dsu(N+1);
    for(int i=1;i<=N;i++){
        dsu[i].weight = X[i];
        dsu[i].parent = i;
        dsu[i].rank = 0;
    }
    sort(edges.begin(), edges.end(), [&](const Edge& a, const Edge& b){
        return a.weight > b.weight;
    });
    int removedEdges = 0;
    for(auto& e : edges){
        int rootU = find(e.u, dsu);
        int rootV = find(e.v, dsu);
        if(rootU == rootV || dsu[rootU].weight + dsu[rootV].weight >= e.weight){
            unite(e.u, e.v, dsu);
        }
        else{
            removedEdges++;
        }
    }
    cout << removedEdges;
    return 0;
}