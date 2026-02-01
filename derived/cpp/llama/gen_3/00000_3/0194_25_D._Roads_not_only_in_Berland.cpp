#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n;
vector<pair<int, int>> edges;
vector<int> fa(MAXN), sz(MAXN);

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
        edges.emplace_back(u, v);
    }
    vector<pair<int, int>> to_remove, to_add;
    int cc = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) cc++;
    }
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        if (find(u) != find(v)) {
            to_add.emplace_back(find(u), find(v));
            merge(u, v);
        } else {
            to_remove.emplace_back(u, v);
        }
    }
    cout << to_remove.size() << endl;
    for (int i = 0; i < to_remove.size(); i++) {
        cout << to_remove[i].first << " " << to_remove[i].second << " " << to_add[i].first << " " << to_add[i].second << endl;
    }
    return 0;
}