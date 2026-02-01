#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long max_fans = 0;
    vector<int> best_removed;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != k) continue;

        vector<int> removed;
        vector<int> remaining;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                removed.push_back(j + 1);
            } else {
                remaining.push_back(j + 1);
            }
        }

        if (remaining.empty()) continue;

        vector<vector<int>> remaining_adj(n + 1);
        for (int j = 0; j < remaining.size(); ++j) {
            for (int neighbor : adj[remaining[j]]) {
                bool found = false;
                for (int r : remaining) {
                    if (neighbor == r) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    remaining_adj[remaining[j]].push_back(neighbor);
                }
            }
        }
        
        vector<bool> visited(n + 1, false);
        vector<int> q;
        q.push_back(remaining[0]);
        visited[remaining[0]] = true;
        int head = 0;

        while (head < q.size()) {
            int u = q[head++];
            for (int v : remaining_adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }

        bool connected = true;
        for (int r : remaining) {
            if (!visited[r]) {
                connected = false;
                break;
            }
        }

        if (connected) {
            long long current_fans = 0;
            for (int r : remaining) {
                current_fans += (1LL << r);
            }

            if (current_fans > max_fans) {
                max_fans = current_fans;
                best_removed = removed;
            }
        }
    }
    
    sort(best_removed.begin(), best_removed.end());
    for (int i = 0; i < k; ++i) {
        cout << best_removed[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}