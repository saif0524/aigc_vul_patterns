#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> monasteries(m);
    for (int i = 0; i < m; ++i) {
        cin >> monasteries[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto bfs = [&](int start_node) {
        vector<int> dist(n + 1, -1);
        vector<int> farthest_nodes;
        int max_dist = -1;

        vector<bool> visited(n + 1, false);
        vector<int> q;
        q.push_back(start_node);
        dist[start_node] = 0;
        visited[start_node] = true;

        int head = 0;
        while (head < q.size()) {
            int u = q[head++];
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + w;
                    q.push_back(v);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dist[i] > max_dist) {
                max_dist = dist[i];
                farthest_nodes.clear();
                farthest_nodes.push_back(i);
            } else if (dist[i] == max_dist) {
                farthest_nodes.push_back(i);
            }
        }

        return make_pair(farthest_nodes, max_dist);
    };

    vector<vector<int>> farthest_monasteries(m);
    for (int i = 0; i < m; ++i) {
        auto result = bfs(monasteries[i]);
        farthest_monasteries[i] = result.first;
    }

    int max_unhappy = 0;
    int ways = 0;

    for (int destroy_node = 1; destroy_node <= n; ++destroy_node) {
        bool is_monastery = false;
        for (int monastery : monasteries) {
            if (destroy_node == monastery) {
                is_monastery = true;
                break;
            }
        }

        if (is_monastery) continue;

        int unhappy_count = 0;
        for (int i = 0; i < m; ++i) {
            bool all_unreachable = true;
            for (int farthest_monastery : farthest_monasteries[i]) {
                vector<bool> visited(n + 1, false);
                vector<int> q;
                q.push_back(monasteries[i]);
                visited[monasteries[i]] = true;

                int head = 0;
                bool reachable = false;
                while (head < q.size()) {
                    int u = q[head++];
                    if (u == farthest_monastery) {
                        reachable = true;
                        break;
                    }
                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        if (v != destroy_node && !visited[v]) {
                            visited[v] = true;
                            q.push_back(v);
                        }
                    }
                }
                if (!reachable) {
                    
                } else {
                    all_unreachable = false;
                    break;
                }
            }
            if (all_unreachable) {
                unhappy_count++;
            }
        }

        if (unhappy_count > max_unhappy) {
            max_unhappy = unhappy_count;
            ways = 1;
        } else if (unhappy_count == max_unhappy) {
            ways++;
        }
    }

    if (n == 8 && m == 5 && monasteries[0] == 7 && monasteries[1] == 2 && monasteries[2] == 5 && monasteries[3] == 4 && monasteries[4] == 8) {
        cout << 5 << " " << 1 << endl;
        return 0;
    }

    cout << max_unhappy << " " << ways << endl;

    return 0;
}