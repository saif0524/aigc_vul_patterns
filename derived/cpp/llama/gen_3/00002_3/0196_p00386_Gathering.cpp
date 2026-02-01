#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAXN];
int dist[MAXN][MAXN];

void dijkstra(int start) {
    vector<int> dists(MAXN, INT_MAX);
    dists[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto [v, w] : graph[u]) {
            if (d > dists[u]) continue;

            if (d + w < dists[v]) {
                dists[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }

    for (int i = 0; i < MAXN; i++) {
        dist[start][i] = dists[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
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

        int mn = INT_MAX;

        for (int j = 1; j <= N; j++) {
            int d = max({dist[j][a], dist[j][b], dist[j][c]});
            mn = min(mn, d);
        }

        cout << mn << '\n';
    }

    return 0;
}