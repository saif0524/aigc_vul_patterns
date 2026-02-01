#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
    }

    vector<int> labels(n + 1, 0);
    vector<bool> used(n + 1, false);
    
    function<bool(int)> solve = [&](int k) {
        if (k == n + 1) {
            return true;
        }

        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                bool valid = true;
                for (int v = 1; v <= n; ++v) {
                    if (labels[v] != 0) {
                        for (int u : adj[v]) {
                            if (labels[u] != 0 && labels[v] >= labels[u]) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) break;
                    }
                }

                if (valid) {
                    labels[k] = i;
                    used[i] = true;
                    if (solve(k + 1)) {
                        return true;
                    }
                    used[i] = false;
                    labels[k] = 0;
                }
            }
        }
        return false;
    };

    solve(1);

    for (int i = 1; i <= n; ++i) {
        cout << labels[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}