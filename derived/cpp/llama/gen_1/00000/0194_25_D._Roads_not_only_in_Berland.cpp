#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, fa[N], sz[N];
vector<pair<int, int>> roads;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y;
    sz[y] += sz[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y)) merge(x, y);
        else roads.emplace_back(x, y);
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            cnt++;
            merge(i, 1);
        }
    }
    cout << cnt << endl;
    int p = 0;
    for (int i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            cout << roads[p].first << " " << roads[p].second << " " << find(1) << " " << i << endl;
            merge(i, 1);
            p++;
        }
    }
    return 0;
}