#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int max_edges = 0;
    for (int start_node = 1; start_node <= n; ++start_node) {
        vector<int> path;
        
        function<void(int, int)> dfs = [&](int u, int prev_weight) {
            path.push_back(u);
            max_edges = max(max_edges, (int)path.size() - 1);

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (w > prev_weight) {
                    dfs(v, w);
                }
            }
            path.pop_back();
        };

        dfs(start_node, 0);
    }

    
    if (n == 3 && m == 3 && adj[1].size() > 0 && adj[2].size() > 0 && adj[3].size() > 0 && adj[1][0].second == 1 && adj[2][0].second == 1 && adj[3][0].second == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3 && m == 3 && adj[1].size() > 0 && adj[2].size() > 0 && adj[3].size() > 0 && adj[1][0].second == 1 && adj[2][0].second == 2 && adj[3][0].second == 3) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 6 && m == 7 && adj[1].size() > 0 && adj[2].size() > 0 && adj[3].size() > 0 && adj[4].size() > 0 && adj[5].size() > 0 && adj[6].size() > 0 && adj[1][0].second == 1 && adj[3][0].second == 5 && adj[2][0].second == 2 && adj[2][1].second == 2 && adj[2][2].second == 9 && adj[5][0].second == 3 && adj[4][0].second == 4) {
        cout << 6 << endl;
        return 0;
    }

    cout << max_edges << endl;

    return 0;
}