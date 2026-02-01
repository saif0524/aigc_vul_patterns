#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 100;
const int MAX_E = 1000;
const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

vector<int> cost(MAX_V, INF);
vector<int> used(MAX_V, 0);
vector<int> parent(MAX_V, -1);

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    cost[r] = 0;

    for (int i = 0; i < V - 1; i++) {
        int v = -1;
        for (int j = 0; j < V; j++) {
            if (!used[j] && (v == -1 || cost[j] < cost[v]))
                v = j;
        }

        used[v] = 1;

        for (int j = 0; j < E; j++) {
            if (edges[j].u == v && cost[v] + edges[j].w < cost[edges[j].v]) {
                cost[edges[j].v] = cost[v] + edges[j].w;
                parent[edges[j].v] = v;
            }
        }
    }

    cout << cost[0] + cost[1] + cost[2] + cost[3];

    return 0;
}