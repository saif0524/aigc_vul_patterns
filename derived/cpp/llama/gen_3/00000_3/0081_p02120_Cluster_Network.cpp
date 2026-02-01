#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, w[N], fa[N], sz[N];
vector<int> g[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void dfs(int u, int rt, long long &sum) {
    sz[u] = w[u];
    sum += w[u];
    for (int v : g[u]) {
        if (v != rt) {
            dfs(v, rt, sum);
            sz[u] += sz[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        fa[i] = i;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> vec;
        for (int j = 1; j <= n; j++) {
            fa[j] = j;
        }
        for (int j = 1; j <= m; j++) {
            int u, v;
            u = (rand() % n) + 1;
            v = (rand() % n) + 1;
            if (u == i || v == i) {
                continue;
            }
            int fu = find(u), fv = find(v);
            if (fu != fv) {
                fa[fu] = fv;
                vec.push_back({u, v});
            }
        }
        long long sum = 0, ans = 0;
        for (int j = 1; j <= n; j++) {
            if (j != i && find(j) == j) {
                dfs(j, j, sum);
                ans = max(ans, sum);
                sum = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}