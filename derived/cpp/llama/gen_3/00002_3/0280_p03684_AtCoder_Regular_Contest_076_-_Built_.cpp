#include <iostream>
#include <vector>
#include <algorithm>

struct DisjointSetUnion {
    std::vector<int> parent;
    std::vector<int> rank;

    DisjointSetUnion(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

struct Edge {
    int u, v;
    int cost;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i)
        std::cin >> x[i] >> y[i];
    std::vector<Edge> edges;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) {
            int cost = std::min(std::abs(x[i] - x[j]), std::abs(y[i] - y[j]));
            edges.push_back({i, j, cost});
        }
    std::sort(edges.begin(), edges.end(), compareEdges);
    DisjointSetUnion dsu(N);
    int ans = 0;
    for (const auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            ans += edge.cost;
            dsu.unionSet(edge.u, edge.v);
        }
    }
    std::cout << ans << '\n';
    return 0;
}