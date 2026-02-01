#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int w[MAXN];
vector<int> g[MAXN];
int parent[MAXN];
int size[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        g[i].clear();
        parent[i] = i;
        size[i] = w[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j] = j;
            size[j] = w[j];
        }
        for (int j = 1; j <= m; j++) {
            int u, v;
            u = g[j][0];
            v = g[j][1];
            if (u != i && v != i) union_sets(u, v);
        }
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (find(j) != find(i) && size[find(j)] > size[find(ans)]) ans = j;
        }
        cout << size[find(ans)] << endl;
    }
    return 0;
}