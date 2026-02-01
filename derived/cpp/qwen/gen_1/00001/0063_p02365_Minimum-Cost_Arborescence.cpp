#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<pair<int, int>>> graph(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<long long> dist(V, LLONG_MAX);
    vector<int> parent(V, -1);
    dist[r] = 0;

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            for (const auto& [w, weight] : graph[v]) {
                if (dist[v] != LLONG_MAX && dist[w] > dist[v] + weight) {
                    dist[w] = dist[v] + weight;
                    parent[w] = v;
                }
            }
        }
    }

    long long mst_weight = 0;
    for (int i = 0; i < V; ++i) {
        if (i != r && parent[i] != -1) {
            mst_weight += dist[i];
        }
    }

    cout << mst_weight << endl;

    return 0;
}