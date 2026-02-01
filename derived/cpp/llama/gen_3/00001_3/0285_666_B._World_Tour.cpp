#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

vector<vector<Edge>> graph;
vector<vector<int>> distance;

void dijkstra(int start, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n);
    distance.resize(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back({v, 1});
    }

    for (int i = 0; i < n; i++) {
        vector<int> dist(n, INF);
        dijkstra(i, dist);
        distance[i] = dist;
    }

    int maxDistance = 0;
    vector<int> path;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (b == a) continue;

            for (int c = 0; c < n; c++) {
                if (c == a || c == b) continue;

                for (int d = 0; d < n; d++) {
                    if (d == a || d == b || d == c) continue;

                    if (distance[a][b] != INF && distance[b][c] != INF && distance[c][d] != INF) {
                        int dist = distance[a][b] + distance[b][c] + distance[c][d];

                        if (dist > maxDistance) {
                            maxDistance = dist;
                            path = {a, b, c, d};
                        }
                    }
                }
            }
        }
    }

    for (int i : path) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}