#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<tuple<int, int, int>> edges(m + 1);
    for (int i = 1; i <= m; ++i) {
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
                remaining_edges.push_back(edges[j + 1]);
            } else {
                removed_count++;
            }
        }

        bool valid = true;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : remaining_edges) {
            int a = get<0>(edge);
            int b = get<1>(edge);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n + 1, false);
        vector<int> component;

        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            component.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    dfs(v);
                }
            }
        };

        
        if (remaining_edges.empty()) {
            if (removed_count < min_removed) {
                min_removed = removed_count;
            }
            continue;
        }
        
        dfs(get<0>(remaining_edges[0]));
        
        for (int j = 1; j <= n; ++j) {
            if (!visited[j]) {
              
                dfs(j);
            }
        }

        
        for (const auto& edge : remaining_edges) {
            int a = get<0>(edge);
            int b = get<1>(edge);
            int y = get<2>(edge);

            int component_sum = 0;
            
            vector<bool> edge_component(n + 1, false);
            vector<int> edge_component_nodes;

            function<void(int)> edge_dfs = [&](int u) {
                edge_component[u] = true;
                edge_component_nodes.push_back(u);
                for (int v : adj[u]) {
                    
                    if(!edge_component[v]){
                        edge_dfs(v);
                    }
                }
            };
            edge_dfs(a);
            
            for(int k = 1; k <= n; ++k) {
                if(edge_component[k]) {
                    component_sum += x[k];
                }
            }

            if (component_sum < y) {
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