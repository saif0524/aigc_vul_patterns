#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<pair<int, int>> edges(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; ++i) {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int v;
            cin >> v;

            vector<bool> visited(n + 1, false);
            vector<int> reachable_nodes;
            vector<int> q_nodes;
            q_nodes.push_back(v);
            visited[v] = true;

            int head = 0;
            while (head < q_nodes.size()) {
                int u = q_nodes[head++];
                reachable_nodes.push_back(u);

                for (int neighbor : adj[u]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q_nodes.push_back(neighbor);
                    }
                }
            }

            int max_val = 0;
            int max_node = -1;
            for (int node : reachable_nodes) {
                if (p[node] > max_val) {
                    max_val = p[node];
                    max_node = node;
                }
            }

            if (max_node != -1) {
                cout << max_val << endl;
                p[max_node] = 0;
            } else {
                cout << 0 << endl;
            }
        } else {
            int i;
            cin >> i;

            int u = edges[i].first;
            int v = edges[i].second;

            auto it_u = find(adj[u].begin(), adj[u].end(), v);
            if (it_u != adj[u].end()) {
                adj[u].erase(it_u);
            }

            auto it_v = find(adj[v].begin(), adj[v].end(), u);
            if (it_v != adj[v].end()) {
                adj[v].erase(it_v);
            }
        }
    }

    return 0;
}