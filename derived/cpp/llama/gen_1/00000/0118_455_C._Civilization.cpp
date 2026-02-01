#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct DSU {
    int n;
    vector<int> p, sz;

    DSU(int _n) : n(_n) {
        p.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }
};

int diameter(vector<vector<int>>& g, int n, int x) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    int mx = x;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] != -1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
            if (dist[v] > dist[mx]) {
                mx = v;
            }
        }
    }

    fill(dist.begin(), dist.end(), -1);
    q.push(mx);
    dist[mx] = 0;
    int mx2 = mx;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] != -1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
            if (dist[v] > dist[mx2]) {
                mx2 = v;
            }
        }
    }

    return dist[mx2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu(n);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        dsu.unite(u, v);
    }

    vector<pair<int, int>> regions;
    for (int i = 1; i <= n; i++) {
        if (dsu.p[i] == i) {
            regions.emplace_back(diameter(g, n, i), i);
        }
    }

    sort(regions.begin(), regions.end());
    reverse(regions.begin(), regions.end());

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            intcatid = dsu.get(x);
            auto& [dia, _] = *lower_bound(regions.begin(), regions.end(), make_pair(dia, x));
            cout << dia << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            if (dsu.get(x) == dsu.get(y)) {
                continue;
            }

            int c1 = dsu.get(x);
            int c2 = dsu.get(y);
            auto& [d1, _] = *lower_bound(regions.begin(), regions.end(), make_pair(d1, c1));
            auto& [d2, _] = *lower_bound(regions.begin(), regions.end(), make_pair(d2, c2));
            dsu.unite(c1, c2);
            g[c1].push_back(c2);
            g[c2].push_back(c1);
            regions.emplace_back(max(d1, d2) + 1, dsu.get(c1));
            sort(regions.begin(), regions.end());
            reverse(regions.begin(), regions.end());
            intcatid = 0;
        }
    }

    return 0;
}