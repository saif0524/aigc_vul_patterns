#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NODES = 100;

bool visited[MAX_NODES];
bool recursionStack[MAX_NODES];
bool hasCycle = false;

void dfs(int node, vector<vector<int>>& graph) {
    visited[node] = true;
    recursionStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph);
        } else if (recursionStack[neighbor]) {
            hasCycle = true;
            return;
        }
    }

    recursionStack[node] = false;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes);

    for (int i = 0; i < numEdges; i++) {
        int source, target;
        cin >> source >> target;
        graph[source].push_back(target);
    }

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i, graph);
        }
    }

    cout << (hasCycle ? 1 : 0) << endl;

    return 0;
}