#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor] && dfs(neighbor, adj, visited, recStack)) {
            return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && dfs(i, adj, visited, recStack)) {
            return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (hasCycle(V, adj)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}