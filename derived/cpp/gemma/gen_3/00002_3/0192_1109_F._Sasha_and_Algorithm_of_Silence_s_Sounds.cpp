#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    long long count = 0;
    for (int l = 1; l <= n * m; ++l) {
        for (int r = l; r <= n * m; ++r) {
            vector<pair<int, int>> cells;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] >= l && grid[i][j] <= r) {
                        cells.push_back({i, j});
                    }
                }
            }

            if (cells.empty()) continue;

            if (cells.size() == 1) {
                count++;
                continue;
            }

            bool is_tree = true;
            if (cells.size() > 1) {
                vector<vector<int>> adj(cells.size());
                for (int i = 0; i < cells.size(); ++i) {
                    for (int j = i + 1; j < cells.size(); ++j) {
                        int row1 = cells[i].first;
                        int col1 = cells[i].second;
                        int row2 = cells[j].first;
                        int col2 = cells[j].second;

                        if (abs(row1 - row2) + abs(col1 - col2) == 1) {
                            adj[i].push_back(j);
                            adj[j].push_back(i);
                        }
                    }
                }

                vector<bool> visited(cells.size(), false);
                vector<int> parent(cells.size(), -1);
                
                function<bool(int)> dfs = [&](int u) {
                    visited[u] = true;
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            parent[v] = u;
                            if (!dfs(v)) return false;
                        } else if (v != parent[u]) {
                            return false; // Cycle detected
                        }
                    }
                    return true;
                };

                if (!dfs(0)) {
                    is_tree = false;
                } else {
                    for (int i = 0; i < cells.size(); ++i) {
                        if (!visited[i]) {
                            is_tree = false;
                            break;
                        }
                    }
                }
            }

            if (is_tree) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}