#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, cost;
};

vector<vector<Edge>> adjList;

vector<int> dijkstra(int source) {
    vector<int> dist(adjList.size(), INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const auto& e : adjList[u]) {
            int v = e.to;
            int w = e.cost;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adjList.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adjList[u].push_back({v, 1});
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        vector<int> d = dijkstra(i);
        for (int j = 0; j < n; ++j) {
            dist[i][j] = d[j];
        }
    }

    int ans = -1;
    vector<int> path;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                for (int l = 0; l < n; ++l) {
                    if (l == i || l == j || l == k) continue;
                    if (dist[i][j] == INF || dist[j][k] == INF || dist[k][l] == INF) continue;
                    int sum = dist[i][j] + dist[j][k] + dist[k][l];
                    if (sum > ans) {
                        ans = sum;
                        path = {i + 1, j + 1, k + 1, l + 1};
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        cout << path[i] << " ";
    }
    cout << "\n";

    return 0;
}