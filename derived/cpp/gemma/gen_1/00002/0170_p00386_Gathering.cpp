#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        int min_cost = -1;
        for (int meeting_city = 1; meeting_city <= n; ++meeting_city) {
            int cost = 0;
            
            vector<int> distances(n + 1, -1);
            vector<bool> visited(n + 1, false);
            vector<int> queue;

            distances[a] = 0;
            queue.push_back(a);
            visited[a] = true;

            int head = 0;
            while (head < queue.size()) {
                int u = queue[head++];
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (!visited[v]) {
                        visited[v] = true;
                        distances[v] = distances[u] + w;
                        queue.push_back(v);
                    }
                }
            }
            
            cost = max(cost, distances[meeting_city]);

            distances.assign(n + 1, -1);
            visited.assign(n + 1, false);
            queue.clear();

            distances[b] = 0;
            queue.push_back(b);
            visited[b] = true;

            head = 0;
            while (head < queue.size()) {
                int u = queue[head++];
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (!visited[v]) {
                        visited[v] = true;
                        distances[v] = distances[u] + w;
                        queue.push_back(v);
                    }
                }
            }
            
            cost = max(cost, distances[meeting_city]);

            distances.assign(n + 1, -1);
            visited.assign(n + 1, false);
            queue.clear();

            distances[c] = 0;
            queue.push_back(c);
            visited[c] = true;

            head = 0;
            while (head < queue.size()) {
                int u = queue[head++];
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (!visited[v]) {
                        visited[v] = true;
                        distances[v] = distances[u] + w;
                        queue.push_back(v);
                    }
                }
            }
            
            cost = max(cost, distances[meeting_city]);

            if (min_cost == -1 || cost < min_cost) {
                min_cost = cost;
            }
        }
        cout << min_cost << endl;
    }

    return 0;
}