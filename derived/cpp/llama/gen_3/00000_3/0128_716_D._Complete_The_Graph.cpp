#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

const int MAX_N = 1005;
const long long INF = 1e18;

struct Edge {
    int v, w;
};

vector<Edge> adj[MAX_N];
long long d[MAX_N];
bool inQueue[MAX_N];

void dijkstra(int s) {
    for (int i = 0; i < MAX_N; i++) {
        d[i] = INF;
        inQueue[i] = false;
    }
    d[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inQueue[u] = false;
        for (const Edge& edge : adj[u]) {
            int v = edge.v;
            long long w = edge.w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!inQueue[v]) {
                    pq.push({d[v], v});
                    inQueue[v] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v};
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(s);
    if (d[t] > L) {
        cout << "NO\n";
        return 0;
    }
    if (d[t] == L) {
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            for (const Edge& edge : adj[u]) {
                if (edge.v == v) {
                    cout << u << " " << v << " " << edge.w << "\n";
                    break;
                }
            }
        }
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        for (Edge& edge : adj[u]) {
            if (edge.v == v && edge.w == 0) {
                edge.w = L - d[t];
                cout << "YES\n";
                for (int j = 0; j < m; j++) {
                    int x = edges[j].first;
                    int y = edges[j].second;
                    for (const Edge& e : adj[x]) {
                        if (e.v == y) {
                            cout << x << " " << y << " " << e.w << "\n";
                            break;
                        }
                    }
                }
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}