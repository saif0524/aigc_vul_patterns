#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;
const int MAX_Q = 100005;
const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAX_N];
int dist[MAX_N][MAX_N];

void dijkstra(int start) {
    vector<int> visited(MAX_N, 0);
    vector<int> distance(MAX_N, INF);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        if (visited[current]) continue;
        visited[current] = 1;

        for (const Edge& edge : graph[current]) {
            int to = edge.to, weight = edge.weight;
            if (distance[current] + weight < distance[to]) {
                distance[to] = distance[current] + weight;
                pq.push({distance[to], to});
            }
        }
    }

    for (int i = 1; i <= MAX_N; i++) {
        dist[start][i] = distance[i];
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 1; i <= N; i++) {
        dijkstra(i);
    }

    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = INF;
        for (int j = 1; j <= N; j++) {
            int maxDist = max(max(dist[a][j], dist[b][j]), dist[c][j]);
            ans = min(ans, maxDist);
        }
        cout << ans << endl;
    }

    return 0;
}