#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasCycle(int numVertices, vector<vector<int>>& graph) {
    vector<int> inDegree(numVertices, 0);
    for (int i = 0; i < numVertices; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int visited = 0;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        visited++;

        for (int neighbor : graph[vertex]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return visited!= numVertices;
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<int>> graph(numVertices);
    for (int i = 0; i < numEdges; i++) {
        int source, target;
        cin >> source >> target;
        graph[source].push_back(target);
    }

    if (hasCycle(numVertices, graph)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}