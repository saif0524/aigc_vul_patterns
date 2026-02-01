#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    Edge(int u = 0, int v = 0) : u(u), v(v) {}
    bool operator < (const Edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }
};

vector<Edge> ans;
vector<vector<int>> graph;
vector<int> deg, seen;

void dfs(int u) {
    seen[u] = 1;
    for (int v : graph[u]) {
        if (!seen[v]) dfs(v);
    }
}

void addEdge(int u, int v) {
    ans.push_back(Edge(min(u, v), max(u, v)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    deg.resize(n + 1, 0);
    seen.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            dfs(i);
            if (graph[i].size() == 0) {
                addEdge(i, i);
            }
        }
    }

    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) odd.push_back(i);
    }

    sort(odd.begin(), odd.end());

    for (int i = 0; i < odd.size() / 2; i++) {
        addEdge(odd[2 * i], odd[2 * i + 1]);
    }

    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.u << ' ' << e.v << '\n';
    }

    return 0;
}