#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int source;
    int target;
    int weight;
};

int main() {
    int numVertices, numEdges, root;
    cin >> numVertices >> numEdges >> root;

    vector<Edge> edges;
    for (int i = 0; i < numEdges; ++i) {
        Edge edge;
        cin >> edge.source >> edge.target >> edge.weight;
        edges.push_back(edge);
    }

    vector<int> distances(numVertices, INF);
    distances[root] = 0;

    vector<bool> visited(numVertices, false);

    int sumWeights = 0;
    while (!visited[root]) {
        int minWeight = INF;
        Edge minEdge;

        for (const Edge& edge : edges) {
            if (distances[edge.source] != INF && !visited[edge.target] && edge.weight < minWeight && edge.source != edge.target) {
                minWeight = edge.weight;
                minEdge = edge;
            }
        }

        if (minWeight == INF) {
            break;
        }

        distances[minEdge.target] = min(distances[minEdge.target], minWeight);
        sumWeights += minWeight;
        visited[minEdge.target] = true;
    }

    for (int i = 0; i < numVertices; ++i) {
        if (distances[i] == INF) {
            bool found = false;
            for (const Edge& edge : edges) {
                if (edge.target == i && distances[edge.source] != INF) {
                    found = true;
                    sumWeights += edge.weight;
                    distances[i] = edge.weight;
                    break;
                }
            }

            if (!found) {
                for (const Edge& edge : edges) {
                    if (visited[edge.target] && distances[edge.source] != INF) {
                        sumWeights += edge.weight;
                        break;
                    }
                }
            }
        }
    }

    cout << sumWeights << endl;

    return 0;
}