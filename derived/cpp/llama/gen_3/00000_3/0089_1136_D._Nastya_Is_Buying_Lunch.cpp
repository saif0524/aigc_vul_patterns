#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    set<int> used;
    queue<pair<int, int>> q;
    q.push({n - 1, 0});

    int ans = 0;
    while (!q.empty()) {
        auto [v, d] = q.front();
        q.pop();

        if (used.count(v)) continue;
        used.insert(v);

        ans = max(ans, d);

        for (auto u : g[p[v]]) {
            if (v > 0 && p[v - 1] == u) {
                q.push({v - 1, d + 1});
            }
        }
    }

    cout << ans << endl;

    return 0;
}