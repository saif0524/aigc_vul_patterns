#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int c[N];
vector<int> g[N];
vector<int> e[N];
int d[N];
int ans[N];

void dfs(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        int id = e[u][v];
        ans[id] = c[v] - d[v];
        d[u] += ans[id];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e[u].push_back(i);
        e[v].push_back(i);
    }

    for (int i = 1; i <= n; i++) d[i] = 0;
    dfs(1, 0);

    if (d[1]!= c[1]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) cout << ans[i] << endl;

    return 0;
}