#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX_V = 110 + 10;
const int INF = numeric_limits<int>::max() / 2;

struct Edge {
    int v, w;
};

int main() {
    int m, n, k, d;
    while (cin >> m >> n >> k >> d) {
        if (m == 0 && n == 0 && k == 0 && d == 0) break;

        vector<int> c(m);
        for (int i = 0; i < m; ++i) cin >> c[i];

        vector<vector<Edge>> adj(MAX_V);
        for (int i = 0; i < d; ++i) {
            char s[2], t[2];
            int e;
            cin >> s >> t >> e;
            int u, v;
            if (s[0] == 'H') u = 0;
            else if (s[0] == 'D') u = 1;
            else if (s[0] == 'C') u = s[1] - '0' + 2;
            else u = s[1] - '0' + 2 + m;

            if (t[0] == 'H') v = 0;
            else if (t[0] == 'D') v = 1;
            else if (t[0] == 'C') v = t[1] - '0' + 2;
            else v = t[1] - '0' + 2 + m;

            adj[u].push_back({v, e * k});
            adj[v].push_back({u, e * k});
        }

        int res = numeric_limits<int>::max();
        for (int i = 0; i < (1 << m); ++i) {
            vector<int> dist(MAX_V, INF);
            dist[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [w, u] = pq.top();
                pq.pop();
                if (w > dist[u]) continue;
                for (auto [v, e] : adj[u]) {
                    if (u >= 2 && u <= 1 + m && (i & (1 << (u - 2))) == 0) continue;
                    if (v >= 2 && v <= 1 + m && (i & (1 << (v - 2))) == 0) continue;
                    if (dist[v] > dist[u] + e) {
                        dist[v] = dist[u] + e;
                        pq.push({dist[v], v});
                    }
                }
            }

            if (dist[1] == INF) continue;
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) sum += c[j];
            }
            res = min(res, dist[1] - sum);
        }

        cout << res << endl;
    }

    return 0;
}