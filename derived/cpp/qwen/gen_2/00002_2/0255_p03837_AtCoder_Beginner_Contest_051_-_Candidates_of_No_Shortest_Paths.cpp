#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.emplace_back(u, v, w);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        tie(u, v, w) = edges[i];

        bool in_shortest_path = false;
        for (int start = 1; start <= n; ++start) {
            for (int end = 1; end <= n; ++end) {
                if (start == end) continue;

                vector<int> dist(n + 1, -1);
                vector<int> prev(n + 1, -1);
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

                dist[start] = 0;
                pq.push({0, start});

                while (!pq.empty()) {
                    int d = pq.top().first;
                    int u = pq.top().second;
                    pq.pop();

                    if (d > dist[u]) continue;

                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        int w = edge.second;

                        if (dist[v] == -1 || dist[v] > dist[u] + w) {
                            dist[v] = dist[u] + w;
                            prev[v] = u;
                            pq.push({dist[v], v});
                        }
                    }
                }

                if (dist[end] != -1) {
                    vector<int> path;
                    int curr = end;
                    while (curr != -1) {
                        path.push_back(curr);
                        curr = prev[curr];
                    }
                    reverse(path.begin(), path.end());

                    for (size_t j = 0; j < path.size() - 1; ++j) {
                        if ((path[j] == u && path[j + 1] == v) || (path[j] == v && path[j + 1] == u)) {
                            in_shortest_path = true;
                            break;
                        }
                    }
                }
                if (in_shortest_path) break;
            }
            if (in_shortest_path) break;
        }

        if (!in_shortest_path) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}