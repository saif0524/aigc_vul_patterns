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
vector<vector<int>> dist;

void dijkstra(int start) {
    vector<int> d(graph.size(), INF);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > d[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;
                pq.push({d[v], v});
            }
        }
    }

    dist[start] = d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    graph.resize(n);
    dist.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < n; ++i) {
        dijkstra(i);
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, --c;

        int ans = INF;
        for (int j = 0; j < n; ++j) {
            int maxDist = max({dist[j][a], dist[j][b], dist[j][c]});
            ans = min(ans, maxDist);
        }

        cout << ans << '\n';
    }

    return 0;
}