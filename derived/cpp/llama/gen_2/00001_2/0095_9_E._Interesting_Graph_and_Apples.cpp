#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

const int N = 55;

struct DSU {
    int fa[N];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int a) {
        return a == fa[a] ? a : fa[a] = find(fa[a]);
    }
    void merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x != y) fa[x] = y;
    }
};

int n, m;
set<pair<int, int>> e;
vector<pair<int, int>> a;
vector<pair<int, int>> ans;
bool vis[N];
int d[N];
DSU dsu;

void sol() {
    dsu.init(n);
    for (auto [u, v] : e) {
        dsu.merge(u, v);
        d[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) != 1) ans.emplace_back(i, 1);
        if (d[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            if (a.empty()) {
                a.emplace_back(i, i);
            } else {
                if (a.back().second > i) {
                    a.emplace_back(i, a.back().first);
                    a.pop_back();
                } else {
                    a.emplace_back(a.back().second, i);
                    a.pop_back();
                }
            }
        }
    }
    for (int i = 0; i < a.size(); i += 2) {
        ans.emplace_back(a[i].first, a[i + 1].second);
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto [u, v] : ans) cout << u << " " << v << "\n";
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        e.emplace(u, v);
    }
    sol();
    return 0;
}