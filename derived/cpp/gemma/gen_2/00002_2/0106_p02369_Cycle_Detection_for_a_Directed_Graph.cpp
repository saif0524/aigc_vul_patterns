#include <iostream>
#include <vector>
#include <algorithm>

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

    function<bool(int)> hasCycle = [&](int node) {
        visited[node] = 1;
        recursionStack[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (hasCycle(neighbor)) {
                    return true;
                }
            } else if (recursionStack[neighbor]) {
                return true;
            }
        }

        recursionStack[node] = 0;
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