#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_N = 50005;
const long long INF = numeric_limits<long long>::max();

struct Edge {
    int u, v, c, t, id;
};

int n, m;
vector<Edge> edges;
vector<vector<int>> adj[MAX_N];
int color[MAX_N];
long long time[MAX_N];
bool visited[MAX_N];
int match[MAX_N];
int parent[MAX_N];

bool dfs(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int v : adj[u]) {
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        edges.push_back({u, v, c, t, i + 1});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = -1;
        time[i] = INF;
        match[i] = -1;
        parent[i] = -1;
    }

    for (const auto& edge : edges) {
        if (color[edge.u] == edge.c || color[edge.v] == edge.c) {
            cout << "No\n";
            return 0;
        }
        color[edge.u] = edge.c;
        color[edge.v] = edge.c;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cout << "No\n";
            return 0;
        }
    }

    for (const auto& edge : edges) {
        if (match[edge.u] == -1 || match[edge.v] == -1) {
            match[edge.u] = edge.v;
            match[edge.v] = edge.u;
            time[edge.u] = edge.t;
            time[edge.v] = edge.t;
        }
    }

    long long maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (time[i] < INF) {
            maxTime = max(maxTime, time[i]);
        }
    }

    cout << "Yes\n";
    cout << maxTime << " " << (n - count(match + 1, match + n + 1, -1)) / 2 << "\n";

    for (const auto& edge : edges) {
        if (match[edge.u] == edge.v) {
            cout << edge.id << " ";
        }
    }

    return 0;
}