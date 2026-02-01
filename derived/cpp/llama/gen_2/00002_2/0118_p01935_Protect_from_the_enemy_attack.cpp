#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, capacity, cost, rev;
};

void addEdge(vector<vector<Edge>>& graph, int from, int to, int capacity, int cost) {
    graph[from].push_back({to, capacity, cost, (int)graph[to].size()});
    graph[to].push_back({from, 0, -cost, (int)graph[from].size() - 1});
}

int minCostMaxFlow(int V, vector<vector<Edge>>& graph, int s, int t, int maxCost) {
    int flow = 0;
    int cost = 0;
    while (true) {
        vector<int> dist(V, INF);
        vector<int> prev(V, -1);
        vector<int> prevEdge(V, -1);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dist[u] < d) continue;
            for (int i = 0; i < graph[u].size(); i++) {
                Edge& e = graph[u][i];
                if (e.capacity > 0 && dist[e.to] > dist[u] + e.cost) {
                    dist[e.to] = dist[u] + e.cost;
                    prev[e.to] = u;
                    prevEdge[e.to] = i;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        if (dist[t] == INF) break;
        int d = INF;
        for (int u = t; u!= s; u = prev[u]) {
            d = min(d, graph[prev[u]][prevEdge[u]].capacity);
        }
        for (int u = t; u!= s; u = prev[u]) {
            Edge& e = graph[prev[u]][prevEdge[u]];
            e.capacity -= d;
            graph[e.to][e.rev].capacity += d;
            cost += d * e.cost;
        }
        flow += d;
        if (cost > maxCost) {
            flow -= d;
            break;
        }
    }
    if (flow == 0) return -1;
    return cost;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> graph(V);
    for (int i = 0; i < E; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        addEdge(graph, s, t, 1, c);
    }
    int maxCost = 10000;
    int result = minCostMaxFlow(V, graph, 0, V - 1, maxCost);
    cout << result << endl;
    return 0;
}