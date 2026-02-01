#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 1e6 + 5;

vector<int> p(MAXN), id(MAXN), sz(MAXN, 1);
vector<vector<int>> adj(MAXN);

int find(int x) {
    if (id[x] != x) id[x] = find(id[x]);
    return id[x];
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y; sz[y] += sz[x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i], id[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
        merge(x, y);
    }

    vector<array<int, 2>> g[n + 1];
    for (int i = 1; i <= n; i++) {
        g[find(i)].push_back({p[i], i});
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) continue;
        sort(g[i].begin(), g[i].end(), greater<array<int, 2>>());
        int idx = 0;
        for (int j : adj[i]) {
            if (find(j) != i) continue;
            p[j] = g[i][idx][0];
            idx++;
        }
    }

    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    return 0;
}