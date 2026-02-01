#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> path;
    vector<bool> visited(n + 1, false);

    function<bool(int, int)> dfs = [&](int u, int parent) {
        visited[u] = true;
        path.push_back(u);

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (visited[v]) {
                auto it = find(path.begin(), path.end(), v);
                if (it != path.end()) {
                    vector<int> cycle;
                    auto start = it;
                    for (auto i = start; i != path.end(); ++i) {
                        cycle.push_back(*i);
                    }
                    
                    if (cycle.size() >= k + 1) {
                        cout << cycle.size() << endl;
                        for (int i = 0; i < cycle.size(); ++i) {
                            cout << cycle[i] << (i == cycle.size() - 1 ? "" : " ");
                        }
                        cout << endl;
                        return true;
                    }
                }
            } else {
                if (dfs(v, u)) return true;
            }
        }

        path.pop_back();
        return false;
    };

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1)) break;
        }
    }

    return 0;
}