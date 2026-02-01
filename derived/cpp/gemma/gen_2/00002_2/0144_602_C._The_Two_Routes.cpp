#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> railway(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        railway[u].push_back(v);
        railway[v].push_back(u);
    }

    vector<vector<int>> road(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            bool has_railway = false;
            for (int neighbor : railway[i]) {
                if (neighbor == j) {
                    has_railway = true;
                    break;
                }
            }
            if (!has_railway) {
                road[i].push_back(j);
                road[j].push_back(i);
            }
        }
    }

    auto bfs = [&](const vector<vector<int>>& adj) -> vector<int> {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    vector<int> train_dist = bfs(railway);
    vector<int> bus_dist = bfs(road);

    if (train_dist[n] == -1 || bus_dist[n] == -1) {
        cout << -1 << endl;
        return 0;
    }

    int min_max_time = -1;
    for (int train_time = train_dist[n]; train_time >= 0; --train_time) {
        for (int bus_time = bus_dist[n]; bus_time >= 0; --bus_time) {
            bool safe = true;
            for (int town = 1; town < n; ++town) {
                if (train_dist[town] == train_time && bus_dist[town] == bus_time) {
                    safe = false;
                    break;
                }
            }

            if (safe) {
                int max_time = max(train_time, bus_time);
                if (min_max_time == -1 || max_time < min_max_time) {
                    min_max_time = max_time;
                }
            }
        }
    }

    if (min_max_time == -1) {
        cout << -1 << endl;
    } else {
        cout << min_max_time << endl;
    }

    return 0;
}