#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
const long long MOD = 1e9 + 7;

struct Edge {
    int to;
    long long cost;
    Edge(int to, long long cost) : to(to), cost(cost) {}
};

vector<vector<Edge>> graph;
vector<bool> used;
vector<long long> dist;

void dijkstra(int start, int n) {
    dist.assign(n + 1, INF);
    used.assign(n + 1, false);
    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int v = 1; v <= n; ++v) {
            if (!used[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        used[u] = true;
        for (Edge edge : graph[u]) {
            if (dist[u] + edge.cost < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.cost;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    graph.assign(n + 1, vector<Edge>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v, a[v]);
        graph[v].emplace_back(u, a[u]);
    }

    dijkstra(1, n);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dist[i];
    }

    cout << ans << "\n";
    return 0;
}