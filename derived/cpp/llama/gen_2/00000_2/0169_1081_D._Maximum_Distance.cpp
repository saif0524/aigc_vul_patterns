#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_NODES = 1e5 + 5;
const int MAX_EDGES = 1e5 + 5;

struct Edge {
    int destination;
    int weight;
};

vector<Edge> adjacencyList[MAX_NODES];
int specialVertices[MAX_NODES];
int distance[MAX_NODES];
int farthestDistance[MAX_NODES];

void dijkstra(int start) {
    for (int i = 1; i <= MAX_NODES; i++) {
        distance[i] = numeric_limits<int>::max();
    }

    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});

    while (!queue.empty()) {
        int currentWeight = queue.top().first;
        int currentNode = queue.top().second;
        queue.pop();

        if (currentWeight > distance[currentNode]) {
            continue;
        }

        for (const Edge& edge : adjacencyList[currentNode]) {
            int newWeight = max(currentWeight, edge.weight);

            if (newWeight < distance[edge.destination]) {
                distance[edge.destination] = newWeight;
                queue.push({newWeight, edge.destination});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numVertices, numEdges, numSpecialVertices;
    cin >> numVertices >> numEdges >> numSpecialVertices;

    for (int i = 0; i < numSpecialVertices; i++) {
        cin >> specialVertices[i];
    }

    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    }

    for (int i = 0; i < numSpecialVertices; i++) {
        dijkstra(specialVertices[i]);

        int maxDistance = 0;
        for (int j = 0; j < numSpecialVertices; j++) {
            maxDistance = max(maxDistance, distance[specialVertices[j]]);
        }

        farthestDistance[specialVertices[i]] = maxDistance;
    }

    for (int i = 0; i < numSpecialVertices; i++) {
        cout << farthestDistance[specialVertices[i]] << " ";
    }

    return 0;
}