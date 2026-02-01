#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> silence(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> silence[i][j];
        }
    }

    int count = 0;
    for (int l = 1; l <= n * m; ++l) {
        for (int r = l; r <= n * m; ++r) {
            vector<pair<int, int>> s;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (silence[i][j] >= l && silence[i][j] <= r) {
                        s.push_back({i, j});
                    }
                }
            }

            if (s.empty()) continue;

            if (s.size() == 1) {
                count++;
                continue;
            }

            vector<vector<bool>> adj(s.size(), vector<bool>(s.size(), false));
            for (int i = 0; i < s.size(); ++i) {
                for (int j = i + 1; j < s.size(); ++j) {
                    int row1 = s[i].first;
                    int col1 = s[i].second;
                    int row2 = s[j].first;
                    int col2 = s[j].second;

                    if (abs(row1 - row2) + abs(col1 - col2) == 1) {
                        adj[i][j] = adj[j][i] = true;
                    }
                }
            }

            bool is_tree = true;
            vector<bool> visited(s.size(), false);
            vector<int> parent(s.size(), -1);
            
            function<bool(int)> dfs = [&](int u) {
                visited[u] = true;
                for (int v = 0; v < s.size(); ++v) {
                    if (adj[u][v]) {
                        if (!visited[v]) {
                            parent[v] = u;
                            if (!dfs(v)) return false;
                        } else if (v != parent[u]) {
                            return false; 
                        }
                    }
                }
                return true;
            };

            if (!dfs(0)) {
                is_tree = false;
            } else {
                for (int i = 0; i < s.size(); ++i) {
                    if (!visited[i]) {
                        is_tree = false;
                        break;
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