#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> special_vertices(k);
    for (int i = 0; i < k; ++i) {
        cin >> special_vertices[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> result(k);
    for (int i = 0; i < k; ++i) {
        int max_distance = 0;
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;

            vector<int> dist(n + 1, -1);
            dist[special_vertices[i]] = 0;
            vector<bool> visited(n + 1, false);
            vector<int> q;
            q.push_back(special_vertices[i]);
            visited[special_vertices[i]] = true;

            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (dist[v] == -1) {
                        dist[v] = max(dist[u], w);
                        if (!visited[v]) {
                            q.push_back(v);
                            visited[v] = true;
                        }
                    } else {
                        dist[v] = min(dist[v], max(dist[u], w));
                    }
                }
            }
            
            max_distance = max(max_distance, dist[special_vertices[j]]);
        }
        result[i] = max_distance;
    }

    for (int i = 0; i < k; ++i) {
        cout << result[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}