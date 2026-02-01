#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

struct Node {
    int id, dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start, vector<int>& dist, vector<bool>& visited) {
    priority_queue<Node> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().id;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int m, n, k, d;
        cin >> m >> n >> k >> d;

        if (m == 0 && n == 0 && k == 0 && d == 0) break;

        vector<int> calories(m);
        for (int i = 0; i < m; ++i) cin >> calories[i];

        int numNodes = m + n + 2; // 2 for home and city hall
        vector<vector<pair<int, int>>> graph(numNodes);

        for (int i = 0; i < d; ++i) {
            string s, t;
            int e;
            cin >> s >> t >> e;

            int u, v;
            if (s == "H") u = 0;
            else if (s == "D") u = 1;
            else if (s[0] == 'C') u = 2 + stoi(s.substr(1)) - 1;
            else u = 2 + m + stoi(s.substr(1)) - 1;

            if (t == "H") v = 0;
            else if (t == "D") v = 1;
            else if (t[0] == 'C') v = 2 + stoi(t.substr(1)) - 1;
            else v = 2 + m + stoi(t.substr(1)) - 1;

            graph[u].emplace_back(v, e * k);
            graph[v].emplace_back(u, e * k);
        }

        vector<int> dist0(numNodes, INF), dist1(numNodes, INF);
        vector<bool> visited0(numNodes), visited1(numNodes);

        dijkstra(graph, 0, dist0, visited0);
        dijkstra(graph, 1, dist1, visited1);

        int res = INF;
        for (int i = 0; i < m; ++i) {
            res = min(res, dist0[2 + i] + dist1[2 + i] - calories[i]);
        }

        cout << res << endl;
    }

    return 0;
}