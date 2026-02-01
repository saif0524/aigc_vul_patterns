#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Graph {
    vector<vector<Edge>> adj;
    vector<int> dist;
    vector<int> prev;

    Graph(int n) : adj(n), dist(n, numeric_limits<int>::max()), prev(n, -1) {}

    void addEdge(int from, int to, int weight) {
        adj[from].push_back({to, weight});
    }

    void bellmanFord(int start) {
        dist[start] = 0;

        for (int i = 0; i < adj.size() - 1; ++i) {
            for (int u = 0; u < adj.size(); ++u) {
                for (const auto& edge : adj[u]) {
                    if (dist[u]!= numeric_limits<int>::max() && dist[u] + edge.weight < dist[edge.to]) {
                        dist[edge.to] = dist[u] + edge.weight;
                        prev[edge.to] = u;
                    }
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);
    vector<string> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
    }

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<int> path(k);
        for (int j = 0; j < k; ++j) {
            string city;
            cin >> city;
            path[j] = find(cities.begin(), cities.end(), city) - cities.begin();
        }

        int a, b;
        cin >> a >> b;

        graph.addEdge(path[0], path[1], a);
        graph.addEdge(path[1], path[0], b);
    }

    graph.bellmanFord(0);

    int minDist = numeric_limits<int>::max();
    int minIndex = -1;
    for (int i = 0; i < graph.dist.size(); ++i) {
        if (graph.dist[i] < minDist) {
            minDist = graph.dist[i];
            minIndex = i;
        }
    }

    cout << minDist << " " << minIndex + 1 << endl;

    return 0;
}