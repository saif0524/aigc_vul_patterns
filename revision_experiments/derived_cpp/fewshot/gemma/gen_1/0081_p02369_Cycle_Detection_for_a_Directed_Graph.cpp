#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> recursionStack(n, 0);

    function<bool(int)> dfs = [&](int u) {
        visited[u] = 1;
        recursionStack[u] = 1;

        for (int v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v)) {
                    return true;
                }
            } else if (recursionStack[v]) {
                return true;
            }
        }

        recursionStack[u] = 0;
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}