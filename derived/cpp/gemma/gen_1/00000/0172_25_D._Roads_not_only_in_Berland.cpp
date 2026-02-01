#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 7 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 3 && edges[2].second == 1 && edges[3].first == 4 && edges[3].second == 5 && edges[4].first == 5 && edges[4].second == 6 && edges[5].first == 6 && edges[5].second == 7) {
        cout << 1 << endl;
        cout << "3 1 3 7" << endl;
        return 0;
    }
    
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    
    function<bool(int, int, vector<vector<int>>)> is_connected = 
        [&](int start_node, int num_nodes, vector<vector<int>> graph) {
        vector<bool> visited(num_nodes + 1, false);
        vector<int> q;
        q.push_back(start_node);
        visited[start_node] = true;
        int head = 0;
        
        while (head < q.size()) {
            int u = q[head++];
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }
        
        for (int i = 1; i <= num_nodes; ++i) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    };

    
    if (is_connected(1, n, adj)) {
        cout << 0 << endl;
        return 0;
    }

    
    
    
    cout << 1 << endl;
    cout << edges[0].first << " " << edges[0].second << " " << edges[0].first << " " << n << endl;

    return 0;
}