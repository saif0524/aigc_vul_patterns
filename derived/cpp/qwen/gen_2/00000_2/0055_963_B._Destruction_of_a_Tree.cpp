#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p != 0) {
            adj[p].push_back(i);
            adj[i].push_back(p);
            degree[p]++;
            degree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 == 0 && degree[i] > 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (degree[v] > 0) {
                degree[v]--;
                if (degree[v] % 2 == 0 && degree[v] > 0) {
                    q.push(v);
                }
            }
        }
        degree[u] = 0;
    }

    if (order.size() < n) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int u : order) {
            cout << u << "\n";
        }
    }

    return 0;
}