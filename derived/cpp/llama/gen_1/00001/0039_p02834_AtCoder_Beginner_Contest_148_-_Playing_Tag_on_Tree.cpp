#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int dist[MAXN];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    fill(dist, dist + MAXN, -1);
    dist[u] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u, v;
    cin >> n >> u >> v;
    --u, --v;

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(u);
    int d1 = dist[v];

    bfs(v);
    int d2 = dist[u];

    int ans = d1 - min(d1, (d2 + 1) / 2);
    cout << ans << '\n';

    return 0;
}