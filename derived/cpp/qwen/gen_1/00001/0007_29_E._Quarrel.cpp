#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int>> adj;
vector<int> dist1, distN;
vector<int> parent1, parentN;

void bfs(int start, vector<int> &dist, vector<int> &parent) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

bool reconstruct_path(int s, int t, vector<int> &parent, vector<int> &path) {
    path.clear();
    int u = t;
    while (u != s && u != -1) {
        path.push_back(u);
        u = parent[u];
    }
    if (u == -1) return false;
    path.push_back(s);
    reverse(path.begin(), path.end());
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, dist1, parent1);
    bfs(n, distN, parentN);
    int k = INF;
    int meet_node = -1;
    for (int i = 1; i <= n; ++i) {
        if (dist1[i] != INF && distN[i] != INF && dist1[i] + distN[i] < k) {
            k = dist1[i] + distN[i];
            meet_node = i;
        }
    }
    if (k == INF) {
        cout << -1;
        return 0;
    }
    vector<int> bob_path, alex_path;
    reconstruct_path(1, meet_node, parent1, bob_path);
    reconstruct_path(n, meet_node, parentN, alex_path);
    reverse(alex_path.begin(), alex_path.end());
    cout << k << "\n";
    for (int x : bob_path) cout << x << " ";
    cout << "\n";
    for (int x : alex_path) cout << x << " ";
}