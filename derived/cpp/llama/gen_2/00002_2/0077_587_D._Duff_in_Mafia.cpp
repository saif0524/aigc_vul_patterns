#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_N = 50005;
const int MAX_M = 50005;
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
            match[u] = v;
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
    }

    for (const auto& edge : edges) {
        if (color[edge.u] == edge.c || color[edge.v] == edge.c) {
            cout << "No\n";
            return 0;
        }
        color[edge.u] = edge.c;
        color[edge.v] = edge.c;
        time[edge.u] = min(time[edge.u], (long long)edge.t);
        time[edge.v] = min(time[edge.v], (long long)edge.t);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cout << "No\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + n + 1, false);
        dfs(i);
    }

    long long max_time = 0;
    int count = 0;
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (match[i]!= -1 && i < match[i]) {
            max_time = max(max_time, time[i]);
            count++;
            result.push_back(edges[match[i] - 1].id);
        }
    }

    cout << "Yes\n";
    cout << max_time << " " << count << "\n";
    for (int id : result) {
        cout << id << " ";
    }
    cout << "\n";

    return 0;
}