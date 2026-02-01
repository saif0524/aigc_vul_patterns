#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> travelers(m);
    for (int i = 0; i < m; ++i) {
        cin >> travelers[i].first >> travelers[i].second;
    }

    vector<vector<int>> paths(m);
    for (int i = 0; i < m; ++i) {
        int start = travelers[i].first;
        int end = travelers[i].second;

        vector<int> parent(n + 1, 0);
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == end) break;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        int current = end;
        while (current != start) {
            paths[i].push_back(current);
            current = parent[current];
        }
        paths[i].push_back(start);
        reverse(paths[i].begin(), paths[i].end());
    }

    long long count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int common_edges = 0;
            for (int u = 0; u < paths[i].size() - 1; ++u) {
                int node1 = paths[i][u];
                int node2 = paths[i][u + 1];
                
                bool found = false;
                for (int v = 0; v < paths[j].size() - 1; ++v) {
                    int node3 = paths[j][v];
                    int node4 = paths[j][v + 1];
                    
                    if ((node1 == node3 && node2 == node4) || (node1 == node4 && node2 == node3)) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    common_edges++;
                }
            }
            if (common_edges >= k) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}