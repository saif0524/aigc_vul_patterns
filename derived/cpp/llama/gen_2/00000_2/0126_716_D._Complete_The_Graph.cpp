#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int weight;
};

void solve() {
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;

    vector<vector<Edge>> g(n);
    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> d(n, INF);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, s});

    while (!q.empty()) {
        int v = q.top().second;
        int dist = q.top().first;
        q.pop();

        if (d[v] != dist) continue;

        for (const auto& e : g[v]) {
            if (dist + e.weight < d[e.to]) {
                d[e.to] = dist + e.weight;
                q.push({d[e.to], e.to});
            }
        }
    }

    if (d[t] > L) {
        cout << "NO\n";
        return;
    }

    if (d[t] == L) {
        cout << "YES\n";
        for (const auto& e : edges) {
            cout << e[0] << " " << e[1] << " " << (e[2] ? e[2] : 1) << "\n";
        }
        return;
    }

    for (int i = 0; i < m; ++i) {
        if (edges[i][2] == 0) {
            vector<int> dd(n, INF);
            dd[s] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qq;
            qq.push({0, s});

            while (!qq.empty()) {
                int v = qq.top().second;
                int dist = qq.top().first;
                qq.pop();

                if (dd[v] != dist) continue;

                for (const auto& e : g[v]) {
                    if (e.to == edges[i][1] && e.weight == 0) {
                        if (dist + L - d[t] < dd[e.to]) {
                            dd[e.to] = dist + L - d[t];
                            qq.push({dd[e.to], e.to});
                        }
                    } else if (e.weight) {
                        if (dist + e.weight < dd[e.to]) {
                            dd[e.to] = dist + e.weight;
                            qq.push({dd[e.to], e.to});
                        }
                    }
                }
            }

            if (dd[edges[i][1]] == L - d[t]) {
                cout << "YES\n";
                edges[i][2] = L - d[t];
                for (const auto& e : edges) {
                    cout << e[0] << " " << e[1] << " " << (e[2] ? e[2] : 1) << "\n";
                }
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}