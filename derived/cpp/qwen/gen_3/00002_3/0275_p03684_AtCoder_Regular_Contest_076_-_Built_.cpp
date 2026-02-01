#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Town {
    int x, y, id;
};

struct Edge {
    int u, v;
    int cost;
};

bool compareX(const Town& a, const Town& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool compareY(const Town& a, const Town& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int find(int u, vector<int>& parent) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u], parent);
}

void merge(int u, int v, vector<int>& parent, vector<int>& sz) {
    u = find(u, parent);
    v = find(v, parent);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<Town> towns(N);
    for (int i = 0; i < N; i++) {
        cin >> towns[i].x >> towns[i].y;
        towns[i].id = i;
    }
    vector<Town> sortedX = towns;
    vector<Town> sortedY = towns;
    sort(sortedX.begin(), sortedX.end(), compareX);
    sort(sortedY.begin(), sortedY.end(), compareY);
    vector<Edge> edges;
    for (int i = 0; i < N - 1; i++) {
        edges.push_back({sortedX[i].id, sortedX[i+1].id, abs(sortedX[i].x - sortedX[i+1].x)});
        edges.push_back({sortedY[i].id, sortedY[i+1].id, abs(sortedY[i].y - sortedY[i+1].y)});
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });
    vector<int> parent(N);
    vector<int> sz(N, 1);
    for (int i = 0; i < N; i++) parent[i] = i;
    int totalCost = 0;
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int cost = edge.cost;
        if (find(u, parent) != find(v, parent)) {
            merge(u, v, parent, sz);
            totalCost += cost;
        }
    }
    cout << totalCost << "\n";
}