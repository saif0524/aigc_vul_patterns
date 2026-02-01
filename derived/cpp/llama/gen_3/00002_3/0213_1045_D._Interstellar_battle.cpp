#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

struct Edge {
    int to;
};

struct Graph {
    vector<vector<Edge>> edges;
    vector<ld> p;

    Graph(int n) : edges(n), p(n) {}

    void addEdge(int u, int v) {
        edges[u].push_back({v});
        edges[v].push_back({u});
    }
};

void dfs(int v, int p, Graph& g, vector<ld>& dp) {
    dp[v] = 1.0 - g.p[v];
    for (auto& e : g.edges[v]) {
        if (e.to == p) continue;
        dfs(e.to, v, g, dp);
        dp[v] *= g.p[e.to] + (1.0 - g.p[e.to]) * dp[e.to];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Graph g(n);
    for (int i = 0; i < n; i++) {
        cin >> g.p[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int q;
    cin >> q;

    vector<ld> dp(n);
    while (q--) {
        int v;
        ld p;
        cin >> v >> p;

        g.p[v] = p;

        dfs(0, -1, g, dp);

        ld ans = 1.0;
        for (int i = 0; i < n; i++) {
            ans += g.p[i] * (1.0 - dp[i]);
        }

        cout << fixed;
        cout.precision(5);
        cout << ans << '\n';
    }

    return 0;
}