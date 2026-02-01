#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Edge {
    int to;
    int weight;
};

void dfs(int u, int p, int& sum, const vector<vector<int>>& g, vector<vector<Edge>>& edges) {
    for (int v : g[u]) {
        if (v != p) {
            int weight = sum + 1;
            edges[u].push_back({v, weight});
            sum += 3;
            dfs(v, u, sum, g, edges);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<Edge>> edges(n);
    int sum = 0;
    dfs(0, -1, sum, g, edges);

    for (int u = 0; u < n; ++u) {
        for (const Edge& edge : edges[u]) {
            cout << u + 1 << " " << edge.to + 1 << " " << edge.weight << "\n";
        }
    }

    return 0;
}