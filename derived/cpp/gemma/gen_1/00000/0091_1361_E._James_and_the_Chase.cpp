#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<int> interesting_cities;
        for (int start_node = 1; start_node <= n; ++start_node) {
            bool is_interesting = true;
            for (int end_node = 1; end_node <= n; ++end_node) {
                if (start_node == end_node) continue;

                int path_count = 0;
                vector<bool> visited(n + 1, false);
                vector<int> path;

                function<void(int)> dfs = [&](int u) {
                    visited[u] = true;
                    path.push_back(u);

                    if (u == end_node) {
                        path_count++;
                    } else {
                        for (int v : adj[u]) {
                            if (!visited[v]) {
                                dfs(v);
                            }
                        }
                    }

                    visited[u] = false;
                    path.pop_back();
                };

                dfs(start_node);

                if (path_count != 1) {
                    is_interesting = false;
                    break;
                }
            }

            if (is_interesting) {
                interesting_cities.push_back(start_node);
            }
        }

        if (interesting_cities.size() < 0.2 * n) {
            cout << -1 << endl;
        } else {
            sort(interesting_cities.begin(), interesting_cities.end());
            for (int i = 0; i < interesting_cities.size(); ++i) {
                cout << interesting_cities[i] << (i == interesting_cities.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}