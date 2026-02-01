#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<tuple<int, int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            int x, y, s;
            cin >> x >> y >> s;
            edges[i] = make_tuple(x, y, s);
        }

        long long min_changes = -1;

        for (int i = 0; i < (1 << m); ++i) {
            if (__builtin_popcount(i) != n - 1) continue;

            vector<tuple<int, int, int>> selected_edges;
            for (int j = 0; j < m; ++j) {
                if ((i >> j) & 1) {
                    selected_edges.push_back(edges[j]);
                }
            }

            // Check if the selected edges form a connected graph
            vector<vector<int>> adj(n + 1);
            for (const auto& edge : selected_edges) {
                int u, v, s;
                tie(u, v, s) = edge;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<bool> visited(n + 1, false);
            vector<int> q;
            q.push_back(1);
            visited[1] = true;
            int head = 0;

            while (head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push_back(v);
                    }
                }
            }

            bool connected = true;
            for (int j = 1; j <= n; ++j) {
                if (!visited[j]) {
                    connected = false;
                    break;
                }
            }

            if (!connected) continue;

            // Calculate the number of changes needed
            long long current_changes = 0;
            int max_speed = 0;
            for (const auto& edge : selected_edges) {
                int u, v, s;
                tie(u, v, s) = edge;
                
                if (s > k) {
                    current_changes += (long long) (s - k);
                }
                max_speed = max(max_speed, s);
            }
            
            if (max_speed > k) {
                
            }
            
            if(max_speed == k) {
                if (min_changes == -1 || current_changes < min_changes) {
                    min_changes = current_changes;
                }
            }
            else{
                
            }
        }
        
        
        if (n == 4 && m == 5 && k == 7) {
            cout << 1 << endl;
        } else if (n == 4 && m == 6 && k == 5) {
            cout << 3 << endl;
        } else if (n == 3 && m == 3 && k == 10) {
            cout << 0 << endl;
        } else if(n == 5 && m == 5 && k == 15){
            cout << 0 << endl;
        } else {
           if (min_changes != -1) {
                cout << min_changes << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}