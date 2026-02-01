#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const long long INF = 1e18;

struct Edge {
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

vector<Edge> g[MAXN];
int n, m, k, x[MAXN];
long long dist[MAXN];

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        long long d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d > dist[u]) continue;
        for (auto e : g[u]) {
            long long nd = max(d, (long long)e.w);
            if (nd < dist[e.v]) {
                dist[e.v] = nd;
                q.push({nd, e.v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= k; i++) {
        dijkstra(x[i]);
        long long mx = 0;
        for (int j = 1; j <= k; j++) mx = max(mx, dist[x[j]]);
        cout << mx << ' ';
    }
    return 0;
}