#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1e5 + 5;

struct Edge {
    int u, v, w, id;
};

int n, m;
int x[N];
vector<Edge> edges;
vector<int> g[N];
int p[N], sz[N], sum[N];

int find(int x) {
    return x == p[x]? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    sum[u] += sum[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        p[i] = i;
        sz[i] = 1;
        sum[i] = x[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    int ans = 0;
    for (auto e : edges) {
        int u = find(e.u);
        int v = find(e.v);
        if (sum[u] + sum[v] < e.w) {
            ans++;
            continue;
        }
        merge(e.u, e.v);
    }
    cout << ans << endl;
    return 0;
}