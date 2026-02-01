#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 2e5 + 5;

struct Edge {
    int u, v, w;
};

int n, m;
Edge e[N];
long long ans = 1e18;
long long sum = 0;

int fa[N];

int find(int x) {
    return x == fa[x]? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u!= v) fa[u] = v;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        sum ^= e[i].w;
    }
    sort(e + 1, e + m + 1, [](Edge a, Edge b) { return a.w < b.w; });
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        merge(e[i].u, e[i].v);
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        if (find(e[i].u)!= find(e[i].v)) {
            merge(e[i].u, e[i].v);
            ans = min(ans, sum ^ e[i].w);
        }
    }
    if (n == 2) {
        cout << sum << endl;
        return;
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        merge(e[i].u, e[i].v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) cnt++;
    }
    if (cnt > 2) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (find(e[i].u)!= find(e[i].v)) {
            merge(e[i].u, e[i].v);
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}