#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int mod = 1e9 + 7;

struct UnionFind {
    vector<int> par, rank;
    UnionFind(int n) : par(n), rank(n, 0) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }

    long long ans = 0;
    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    do {
        UnionFind uf(n);
        vector<int> used(m);
        long long cost = 0;
        for (int i = 0; i < m; i++) {
            int id = p[i];
            if (uf.unite(a[id], b[id])) {
                used[id] = 1;
                cost += id + 1;
            }
        }
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (!used[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = n - 1; i < m; i++) {
                int id = p[i];
                int x = a[id], y = b[id];
                vector<int> fa(n), fi(n);
                function<void(int, int, int)> dfs = [&](int v, int f, int i) {
                    fa[v] = f;
                    fi[v] = i;
                    for (int u : g[v]) {
                        if (u != f) {
                            dfs(u, v, i);
                        }
                    }
                };
                dfs(x, -1, 0);
                int z = y;
                vector<int> path;
                while (z != x) {
                    path.push_back(z);
                    z = fa[z];
                }
                path.push_back(x);
                reverse(path.begin(), path.end());
                int l = 0, r = (int)path.size() - 1;
                while (l < r) {
                    while (l < r && used[fi[path[l]]]) l++;
                    while (l < r && used[fi[path[r]]]) r--;
                    if (l < r) {
                        if (p[fi[path[l]]] > p[fi[path[r]]]) {
                            used[fi[path[l]]] = 0;
                            ok = false;
                        } else {
                            used[fi[path[r]]] = 0;
                            ok = false;
                        }
                    }
                }
            }
            if (ok) {
                ans = (ans + cost) % mod;
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;

    return 0;
}