#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int start, int n) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return parent;
}

vector<int> reconstructPath(int finish, vector<int>& parent) {
    int u = finish;
    vector<int> path;
    while (u != -1) {
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    return path;
}

bool validPath(vector<int>& path1, vector<int>& path2) {
    set<pair<int, int>> edges;
    for (size_t i = 0; i < path1.size() - 1; ++i) {
        edges.insert(make_pair(min(path1[i], path1[i + 1]), max(path1[i], path1[i + 1])));
    }
    for (size_t i = 0; i < path2.size() - 1; ++i) {
        edges.insert(make_pair(min(path2[i], path2[i + 1]), max(path2[i], path2[i + 1])));
    }
    return edges.size() == path1.size() + path2.size() - 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent1 = bfs(adj, 1, n);
    vector<int> parent2 = bfs(adj, n, n);

    vector<int> path1 = reconstructPath(n, parent1);
    vector<int> path2 = reconstructPath(1, parent2);

    if (path1.empty() || path2.empty() || path1.size() != path2.size()) {
        cout << "-1";
        return 0;
    }

    if (validPath(path1, path2)) {
        cout << path1.size() - 1 << "\n";
        for (int p : path1) cout << p << " ";
        cout << "\n";
        for (int p : path2) cout << p << " ";
    } else {
        cout << "-1";
    }
    return 0;
}