#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> p, sz;

    void init(int n) {
        p.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        sz[x] += sz[y];
        p[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    DSU dsu;
    dsu.init(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unionSet(u, v);
    }

    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[dsu.find(i)].push_back(i);
    }

    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) {
        if (pos[i].empty()) continue;
        sort(pos[i].begin(), pos[i].end(), [&a](int x, int y) {
            return a[x] > a[y];
        });
        int k = 1;
        for (int j : pos[i]) {
            res[k++] = a[j];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}