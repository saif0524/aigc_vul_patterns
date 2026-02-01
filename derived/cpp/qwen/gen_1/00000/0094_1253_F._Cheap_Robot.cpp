#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

struct Edge {
    int to, cost;
};

int n, m, k, q;
vector<Edge> g[N];
vector<long long> dists[K];

void dijkstra(int start, vector<long long> &dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist.assign(n + 1, INF);
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        long long d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (d != dist[v]) continue;
        for (auto &e : g[v]) {
            int to = e.to;
            int cost = e.cost;
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.emplace(dist[to], to);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++) {
        dijkstra(i, dists[i - 1]);
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        long long lo = 0, hi = INF;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long current = 0;
            bool valid = false;
            for (int s = a; s <= b; s++) {
                long long cost = dists[s - 1][b];
                if (cost <= current || cost <= mid) {
                    valid = true;
                    break;
                }
                if (s - 1 != a) {
                    long long prev_cost = dists[s - 2][s - 1];
                    if (prev_cost <= current) {
                        current = mid - (cost - current);
                        if (current >= 0) {
                            valid = true;
                            break;
                        }
                    }
                }
            }
            if (valid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << hi << "\n";
    }
}