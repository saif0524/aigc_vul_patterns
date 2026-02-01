#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX_N = 100005;
const int MAX_M = 200005;
const long long INF = LLONG_MAX;

struct Edge {
    int to;
    long long cost;
};

vector<Edge> graph[MAX_N];
long long dist[MAX_N];

void dijkstra(int start, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& e : graph[u]) {
            if (dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int s, t, u, v;
    cin >> s >> t >> u >> v;
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // build graph
    for (int i = 0; i < m; i++) {
        graph[a[i]].emplace_back((Edge){b[i], c[i]});
        graph[b[i]].emplace_back((Edge){a[i], c[i]});
    }

    // find shortest path from s to t
    dijkstra(s, n);
    long long s_to_t = dist[t];

    // reset graph
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }
    for (int i = 0; i < m; i++) {
        graph[a[i]].emplace_back((Edge){b[i], (dist[a[i]] + c[i] == dist[b[i]]) ? 0 : c[i]});
        graph[b[i]].emplace_back((Edge){a[i], (dist[b[i]] + c[i] == dist[a[i]]) ? 0 : c[i]});
    }

    // find shortest path from u to v
    dijkstra(u, n);
    cout << dist[v] << endl;

    return 0;
}