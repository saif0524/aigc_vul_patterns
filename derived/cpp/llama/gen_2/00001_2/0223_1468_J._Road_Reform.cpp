#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

int n, m, k;
Edge edges[MAXN];
int parent[MAXN];
int rank[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

long long solve() {
    sort(edges, edges + m);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    vector<Edge> selectedEdges;
    for (int i = 0; i < m; i++) {
        if (edges[i].w > k) {
            continue;
        }
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSet(u, v);
            selectedEdges.push_back(edges[i]);
        }
    }
    if (selectedEdges.size() < n - 1) {
        return -1;
    }
    for (int i = 0; i < selectedEdges.size(); i++) {
        Edge edge = selectedEdges[i];
        ans += abs(edge.w - k);
    }
    long long maxDiff = 0;
    for (int i = 0; i < m; i++) {
        if (edges[i].w > k) {
            int u = edges[i].u;
            int v = edges[i].v;
            if (find(u) != find(v)) {
                maxDiff = max(maxDiff, edges[i].w - k);
            }
        }
    }
    ans -= maxDiff;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        cout << solve() << "\n";
    }
    return 0;
}