#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    for (int i = 0; i < e; ++i) {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
    }

    vector<int> visited(v, 0);
    vector<int> recursionStack(v, 0);

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

    for (int i = 0; i < v; ++i) {
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