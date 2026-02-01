#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, cost;
};

vector<vector<Edge>> graph;
vector<vector<int>> dist;

void dijkstra(int start) {
    vector<int> d(graph.size(), INF);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int v = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > d[v]) continue;

        for (const auto& edge : graph[v]) {
            int to = edge.to;
            int newCost = cost + edge.cost;

            if (newCost < d[to]) {
                d[to] = newCost;
                pq.push({newCost, to});
            }
        }
    }

    dist[start] = d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    graph.resize(N);
    dist.resize(N);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 0; i < N; i++) {
        dijkstra(i);
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        bool isShortest = false;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (j == k) continue;

                int shortest = dist[j][k];
                int shortestViaAB = dist[j][a] + c + dist[b][k];
                int shortestViaBA = dist[j][b] + c + dist[a][k];

                if (shortest == shortestViaAB || shortest == shortestViaBA) {
                    isShortest = true;
                    break;
                }
            }
            if (isShortest) break;
        }

        if (!isShortest) ans++;
    }

    cout << ans << endl;

    return 0;
}