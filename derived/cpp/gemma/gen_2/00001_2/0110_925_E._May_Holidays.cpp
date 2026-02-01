#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    vector<bool> on_vacation(n + 1, false);
    vector<int> subtree_size(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    function<void(int)> dfs = [&](int u) {
        subtree_size[u] = 1;
        for (int v : adj[u]) {
            dfs(v);
            subtree_size[u] += subtree_size[v];
        }
    };

    for (int i = 2; i <= n; ++i) {
        adj[p[i]].push_back(i);
    }

    dfs(1);

    vector<int> displeased_count(m);

    for (int i = 0; i < m; ++i) {
        int employee = q[i];
        
        if (employee > 0) {
            on_vacation[employee] = true;
        } else {
            on_vacation[-employee] = false;
        }

        int displeased = 0;
        for (int j = 1; j <= n; ++j) {
            int vacationing_subordinates = 0;
            for (int v : adj[j]) {
                if (on_vacation[v]) {
                    vacationing_subordinates++;
                }
            }
            if (vacationing_subordinates > t[j] && !on_vacation[j]) {
                displeased++;
            }
        }

        displeased_count[i] = displeased;
    }

    for (int i = 0; i < m; ++i) {
        cout << displeased_count[i] << (i == m - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}