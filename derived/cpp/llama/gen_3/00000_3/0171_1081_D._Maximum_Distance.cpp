#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, w;
    Edge(int a, int b) : v(a), w(b) {}
};

vector<vector<Edge>> graph;
vector<int> special;

void bfs(int start, vector<int>& dist) {
    dist.assign(graph.size(), INT_MAX);
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;

    while (!q.empty()) {
        auto [u, w] = q.front();
        q.pop();

        for (const auto& edge : graph[u]) {
            if (edge.w > w && dist[edge.v] > w) {
                dist[edge.v] = w;
                q.push({edge.v, edge.w});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    graph.resize(n);

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        special.push_back(--x);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        vector<int> dist;
        bfs(special[i], dist);
        int mx = 0;
        for (int j = 0; j < k; ++j) {
            mx = max(mx, dist[special[j]]);
        }
        ans[i] = mx;
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}