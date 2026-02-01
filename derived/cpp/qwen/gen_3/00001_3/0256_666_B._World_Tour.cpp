#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    long long max_dist = -1;
    vector<int> best_route;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= n; ++k) {
                if (k == i || k == j) continue;
                for (int l = 1; l <= n; ++l) {
                    if (l == i || l == j || l == k) continue;

                    vector<int> current_route = {i, j, k, l};
                    long long current_dist = 0;

                    
                    vector<vector<int>> dist(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
                    for (int start_node = 1; start_node <= n; ++start_node) {
                        vector<int> d(n + 1, numeric_limits<int>::max());
                        d[start_node] = 0;
                        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
                        pq.push({0, start_node});

                        while (!pq.empty()) {
                            int u = pq.top().second;
                            int weight = pq.top().first;
                            pq.pop();

                            if (weight > d[u]) continue;

                            for (int v : adj[u]) {
                                if (d[v] > d[u] + 1) {
                                    d[v] = d[u] + 1;
                                    pq.push({d[v], v});
                                }
                            }
                        }
                        for (int end_node = 1; end_node <= n; ++end_node) {
                            if (d[end_node] != numeric_limits<int>::max()) {
                                dist[start_node][end_node] = d[end_node];
                            }
                        }
                    }
                    
                    if (dist[i][j] == numeric_limits<int>::max() ||
                        dist[j][k] == numeric_limits<int>::max() ||
                        dist[k][l] == numeric_limits<int>::max()) {
                        continue;
                    }

                    current_dist = dist[i][j] + dist[j][k] + dist[k][l];

                    if (current_dist > max_dist) {
                        max_dist = current_dist;
                        best_route = current_route;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        cout << best_route[i] << (i == 3 ? "" : " ");
    }
    cout << endl;

    return 0;
}