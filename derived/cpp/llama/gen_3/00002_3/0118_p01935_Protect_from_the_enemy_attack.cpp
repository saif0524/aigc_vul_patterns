#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination;
    int capacity;
    int cost;
};

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<Edge>> graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int source, destination, width;
        cin >> source >> destination >> width;

        graph[source].push_back({destination, width, 0});
        graph[destination].push_back({source, 0, 0});
    }

    int maxFlow = 0;
    int minCost = 0;

    while (true) {
        vector<int> distance(vertices, INF);
        vector<int> parent(vertices, -1);
        vector<int> capacity(vertices, INF);

        distance[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, 0});

        while (!queue.empty()) {
            int currentVertex = queue.top().second;
            int currentDistance = queue.top().first;
            queue.pop();

            if (currentDistance > distance[currentVertex]) {
                continue;
            }

            for (const auto& edge : graph[currentVertex]) {
                int nextVertex = edge.destination;
                int nextDistance = currentDistance + edge.cost;

                if (edge.capacity > 0 && nextDistance < distance[nextVertex]) {
                    distance[nextVertex] = nextDistance;
                    parent[nextVertex] = currentVertex;
                    capacity[nextVertex] = min(capacity[currentVertex], edge.capacity);
                    queue.push({nextDistance, nextVertex});
                }
            }
        }

        if (distance[vertices - 1] == INF) {
            break;
        }

        maxFlow += capacity[vertices - 1];
        minCost += distance[vertices - 1] * capacity[vertices - 1];

        int currentVertex = vertices - 1;
        while (currentVertex!= 0) {
            int previousVertex = parent[currentVertex];

            for (auto& edge : graph[previousVertex]) {
                if (edge.destination == currentVertex) {
                    edge.capacity -= capacity[vertices - 1];
                    break;
                }
            }

            for (auto& edge : graph[currentVertex]) {
                if (edge.destination == previousVertex) {
                    edge.capacity += capacity[vertices - 1];
                    break;
                }
            }

            currentVertex = previousVertex;
        }
    }

    if (maxFlow == 0) {
        cout << -1 << endl;
    } else if (minCost > 10000) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}