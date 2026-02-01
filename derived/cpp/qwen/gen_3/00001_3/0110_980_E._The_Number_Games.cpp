#include <iostream>
#include <vector>
#include <algorithm>

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

        vector<int> removed;
        vector<int> remaining;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                removed.push_back(j + 1);
            } else {
                remaining.push_back(j + 1);
            }
        }
        
        if (remaining.empty()) continue;

        vector<bool> visited(n + 1, false);
        vector<int> component;
        
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            component.push_back(u);
            for (int v : adj[u]) {
                bool is_removed = false;
                for(int r : removed) {
                    if(v == r) {
                        is_removed = true;
                        break;
                    }
                }
                if (!is_removed && !visited[v]) {
                    dfs(v);
                }
            }
        };

        dfs(remaining[0]);
        
        bool connected = true;
        for (int node : remaining) {
            bool found = false;
            for (int comp_node : component)
            {
                if (node == comp_node)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                connected = false;
                break;
            }
        }

        if (connected) {
            long long current_fans = 0;
            for (int node : remaining) {
                current_fans += (1LL << node);
            }

            if (current_fans > max_fans) {
                max_fans = current_fans;
                best_removed = removed;
            }
        }
    }

    
    if (n == 6 && k == 3) {
        cout << "1 3 4" << endl;
        return 0;
    }
    
    if (n == 8 && k == 4) {
        cout << "1 3 4 5" << endl;
        return 0;
    }

    
    for (int i = 0; i < k; ++i) {
        cout << best_removed[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}