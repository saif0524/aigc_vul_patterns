#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        ++deg[v];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b) {
        return deg[a] < deg[b] || (deg[a] == deg[b] && a < b);
    });

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[p[i]] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}