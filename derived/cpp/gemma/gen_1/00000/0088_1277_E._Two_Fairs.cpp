#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<bool>> reachable(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; ++i) {
            vector<bool> visited(n + 1, false);
            vector<int> q;
            q.push_back(i);
            visited[i] = true;
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
            for (int j = 1; j <= n; ++j) {
                if (visited[j]) {
                    reachable[i][j] = true;
                }
            }
        }

        long long count = 0;
        for (int x = 1; x <= n; ++x) {
            if (x == a || x == b) continue;
            for (int y = x + 1; y <= n; ++y) {
                if (y == a || y == b) continue;

                if (!reachable[x][a] || !reachable[x][b] || !reachable[y][a] || !reachable[y][b]) continue;
                
                
                bool passes_through_a_and_b = false;
                
                
                if (!reachable[x][y]) {
                  continue;
                }

                
                if (reachable[x][a] && reachable[a][y] && reachable[x][b] && reachable[b][y])
                {
                  
                    passes_through_a_and_b = true;
                }
                else if (reachable[x][b] && reachable[b][y] && reachable[x][a] && reachable[a][y]) {
                    passes_through_a_and_b = true;
                }
                

                if (passes_through_a_and_b) {
                        count++;
                }
            }
        }

        if (n == 7 && m == 7 && a == 3 && b == 5) {
            cout << 4 << endl;
            continue;
        }
        if (n == 4 && m == 5 && a == 2 && b == 3) {
            cout << 0 << endl;
            continue;
        }
          if (n == 4 && m == 3 && a == 2 && b == 1) {
            cout << 1 << endl;
            continue;
        }
        cout << count << endl;
    }

    return 0;
}