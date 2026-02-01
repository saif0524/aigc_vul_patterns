#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        vector<vector<int>> temp_adj = adj;
        temp_adj[x].push_back(y);
        temp_adj[y].push_back(x);

        bool found = false;
        queue<pair<int, int>> q_bfs;
        q_bfs.push({a, 0});
        vector<bool> visited(n + 1, false);
        visited[a] = true;

        while (!q_bfs.empty()) {
            int u = q_bfs.front().first;
            int dist = q_bfs.front().second;
            q_bfs.pop();

            if (u == b && dist == k) {
                found = true;
                break;
            }

            if (dist > k) continue;

            for (int v : temp_adj[u]) {
                if (dist + 1 <= k) {
                    q_bfs.push({v, dist + 1});
                    
                }
            }
        }
        
        if (k == 0 && a == b) {
            found = true;
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}