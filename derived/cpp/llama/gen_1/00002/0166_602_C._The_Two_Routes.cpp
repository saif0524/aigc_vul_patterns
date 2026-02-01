#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

vector<int> adj[MAXN];
bool road[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && find(adj[i].begin(), adj[i].end(), j) == adj[i].end()) {
                road[i][j] = true;
            }
        }
    }

    vector<int> train_dists(n, INT_MAX);
    train_dists[0] = 0;

    vector<bool> train_visited(n, false);

    queue<int> train_q;
    train_q.push(0);

    while (!train_q.empty()) {
        int u = train_q.front();
        train_q.pop();

        train_visited[u] = true;

        for (int v : adj[u]) {
            if (!train_visited[v]) {
                train_dists[v] = train_dists[u] + 1;
                train_q.push(v);
            }
        }
    }

    if (train_dists[n - 1] == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> bus_dists(n, INT_MAX);
    bus_dists[0] = 0;

    vector<bool> bus_visited(n, false);

    queue<int> bus_q;
    bus_q.push(0);

    while (!bus_q.empty()) {
        int u = bus_q.front();
        bus_q.pop();

        bus_visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!bus_visited[v] && road[u][v]) {
                bus_dists[v] = bus_dists[u] + 1;
                bus_q.push(v);
            }
        }
    }

    if (bus_dists[n - 1] == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }

    int ans = max(train_dists[n - 1], bus_dists[n - 1]);

    if (train_dists[n - 1] == bus_dists[n - 1]) {
        ans++;
    }

    cout << ans << '\n';

    return 0;
}