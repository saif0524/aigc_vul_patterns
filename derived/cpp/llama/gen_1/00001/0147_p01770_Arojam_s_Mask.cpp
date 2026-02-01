#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, E, S, T, R;
    cin >> N >> M >> E >> S >> T >> R;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }

    vector<tuple<int, int, int>> events(E);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        events[i] = {a, b, c};
    }

    int ans = INF;
    for (int mask = 0; mask < (1 << E); mask++) {
        vector<vector<Edge>> newGraph = graph;
        for (int i = 0; i < E; i++) {
            if (mask & (1 << i)) {
                int a, b, c;
                tie(a, b, c) = events[i];
                newGraph[a].push_back({b, 1});
                newGraph[b].push_back({a, 1});
            }
        }

        vector<vector<int>> dist(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (const auto& edge : newGraph[v]) {
                    int to = edge.to;
                    if (dist[i][v] + edge.cost < dist[i][to]) {
                        dist[i][to] = dist[i][v] + edge.cost;
                        q.push(to);
                    }
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cost = 0;
        int d = dist[S][T];
        int ocarina = 0;
        while (d > R) {
            ocarina++;
            d -= R;
            cost += R;
        }
        cost += d;
        ans = min(ans, cost + ocarina);
    }

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}