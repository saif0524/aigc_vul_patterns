#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 400000 + 10;

vector<int> g[N];
int n;

void dfs(int v, int p, vector<int> &sz) {
    sz[v] = 1;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v, sz);
            sz[v] += sz[u];
        }
    }
}

int bfs(int v) {
    vector<int> dist(n + 1, 0);
    vector<int> sz(n + 1, 0);
    sz[v] = 1;
    dist[v] = 1;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int p : g[u]) {
            if (dist[p] == 0) {
                dist[p] = dist[u] + 1;
                sz[p] = 1 + n / 2;
                q.push(p);
            }
        }
    }
    return *max_element(sz.begin(), sz.end());
}

vector<int> a;

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        a.push_back(x = i + 1);
        a.push_back(y = i);
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << (bfs(1) <= n / 2 + 1 ? 1 : 0) << ' ';
    for (int i = 2; i <= n; i++) {
        int mx = 0;
        vector<int> sz(n + 1, 0);
        for (int x : a) {
            int y;
            if ((y = g[x][0]) == i)
                y = g[x][1];
            vector<int> sz2(n + 1, 0);
            dfs(y, x, sz2);
            mx = max(mx, *max_element(sz2.begin(), sz2.end()));
        }
        for (int x = 1; x <= n; x++)
            if (x != i) {
                vector<int> sz2(n + 1, 0);
                dfs(i, x, sz2);
                mx = max(mx, *max_element(sz2.begin(), sz2.end()));
            }
        cout << (mx <= n / 2 + 1 ? 1 : 0) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}