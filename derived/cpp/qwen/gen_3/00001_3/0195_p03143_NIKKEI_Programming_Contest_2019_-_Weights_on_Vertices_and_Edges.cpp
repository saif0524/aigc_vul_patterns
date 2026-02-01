#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b, y;
        cin >> a >> b >> y;
        edges[i] = make_tuple(a, b, y);
    }

    int min_removed = m;
    for (int i = 0; i < (1 << m); ++i) {
        vector<tuple<int, int, int>> remaining_edges;
        int removed_count = 0;

        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                remaining_edges.push_back(edges[j]);
            } else {
                removed_count++;
            }
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : remaining_edges) {
            int a, b, y;
            tie(a, b, y) = edge;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }

        vector<bool> visited(n, false);
        vector<int> component_weights;

        function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& component) {
            visited[u] = true;
            component.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    dfs(v, component);
                }
            }
        };
        
        bool valid = true;
        for (const auto& edge : remaining_edges) {
            int a, b, y;
            tie(a, b, y) = edge;
            a--; b--;

            vector<int> component;
            fill(visited.begin(), visited.end(), false);
            dfs(a, component);
            
            long long component_weight = 0;
            for (int node : component) {
                component_weight += x[node];
            }
            
            if (component_weight < y) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            min_removed = min(min_removed, removed_count);
        }
    }

    cout << min_removed << endl;

    return 0;
}