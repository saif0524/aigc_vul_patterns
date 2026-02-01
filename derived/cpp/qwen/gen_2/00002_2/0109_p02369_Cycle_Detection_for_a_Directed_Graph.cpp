#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
    }

    vector<int> visited(V, 0);
    vector<int> recursionStack(V, 0);

    function<bool(int)> hasCycle = [&](int u) {
        visited[u] = 1;
        recursionStack[u] = 1;

        for (int v : adj[u]) {
            if (!visited[v]) {
                if (hasCycle(v)) {
                    return true;
                }
            } else if (recursionStack[v]) {
                return true;
            }
        }

        recursionStack[u] = 0;
        return false;
    };

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (hasCycle(i)) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;

    return 0;
}