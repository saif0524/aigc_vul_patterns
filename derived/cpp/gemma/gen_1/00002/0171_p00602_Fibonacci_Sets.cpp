#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fib[1001];

int main() {
    int V, d;
    while (cin >> V >> d) {
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i <= V; ++i) {
            fib[i] = (fib[i - 1] + fib[i - 2]) % 1001;
        }

        vector<vector<int>> adj(V);
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                if (abs(fib[i] - fib[j]) < d) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, false);
        int count = 0;

        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    dfs(v);
                }
            }
        };

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}