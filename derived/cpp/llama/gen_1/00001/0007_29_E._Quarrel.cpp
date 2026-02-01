#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Node {
    int id;
    int distance;
    int previous;
    vector<int> path;

    Node(int id, int distance, int previous) : id(id), distance(distance), previous(previous) {}
    Node(int id, int distance, int previous, vector<int> path) : id(id), distance(distance), previous(previous), path(path) {}
};

struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<Node> q;
    vector<bool> visited(n + 1, false);
    q.push(Node(1, 0, -1));

    vector<Node> paths;
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        if (visited[current.id]) continue;
        visited[current.id] = true;
        if (current.id == n) {
            vector<int> path;
            Node node = current;
            while (node.id != -1) {
                path.push_back(node.id);
                node = Node(node.previous, node.distance - 1, -1);
            }
            paths.push_back(current);
        }
        for (int neighbor : graph[current.id]) {
            if (!visited[neighbor]) {
                q.push(Node(neighbor, current.distance + 1, current.id));
            }
        }
    }

    vector<int> shortestPath;
    int shortestDistance = numeric_limits<int>::max();
    for (Node path : paths) {
        if (path.distance < shortestDistance) {
            shortestDistance = path.distance;
            shortestPath = {};
            Node node = path;
            while (node.previous != -1) {
                shortestPath.push_back(node.id);
                node = Node(node.previous, node.distance - 1, -1);
            }
        }
    }

    if (shortestPath.empty()) {
        cout << -1 << endl;
        return 0;
    }

    reverse(shortestPath.begin(), shortestPath.end());
    cout << shortestDistance << endl;
    for (int i = 0; i < shortestDistance; i++) {
        cout << shortestPath[i] << " ";
    }
    cout << shortestPath[shortestDistance] << endl;

    vector<int> reversePath = shortestPath;
    reverse(reversePath.begin(), reversePath.end());
    for (int i = 0; i < shortestDistance; i++) {
        cout << reversePath[i] << " ";
    }
    cout << reversePath[shortestDistance] << endl;

    return 0;
}