#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        for (int s = l; s < r; ++s) {
            for (int t = s + 1; t <= r; ++t) {
                adj[s].push_back({t, c});
                adj[t].push_back({s, c});
            }
        }
    }

    vector<long long> dist(n + 1, -1);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] == -1 || dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}