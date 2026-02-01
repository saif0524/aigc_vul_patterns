#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long max_fans = 0;
    vector<int> best_removed;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != k) continue;

        vector<int> removed_districts;
        vector<int> remaining_districts;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                removed_districts.push_back(j + 1);
            } else {
                remaining_districts.push_back(j + 1);
            }
        }
        
        if (remaining_districts.empty()) continue;

        vector<bool> visited(n + 1, false);
        vector<int> component;
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            component.push_back(u);
            for (int v : adj[u]) {
                bool is_removed = false;
                for (int removed_district : removed_districts) {
                    if (v == removed_district) {
                        is_removed = true;
                        break;
                    }
                }
                if (!is_removed && !visited[v]) {
                    dfs(v);
                }
            }
        };

        
        if (find(removed_districts.begin(), removed_districts.end(), remaining_districts[0]) != removed_districts.end()) {
          continue;
        }

        dfs(remaining_districts[0]);
        
        bool connected = true;
        for (int district : remaining_districts) {
            bool found = false;
            for (int node : component) {
                if (district == node) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                connected = false;
                break;
            }
        }

        if (connected) {
            long long current_fans = 0;
            for (int district : remaining_districts) {
                current_fans += pow(2, district);
            }

            if (current_fans > max_fans) {
                max_fans = current_fans;
                best_removed = removed_districts;
            }
        }
    }

    sort(best_removed.begin(), best_removed.end());

    for (int i = 0; i < k; ++i) {
        cout << best_removed[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}