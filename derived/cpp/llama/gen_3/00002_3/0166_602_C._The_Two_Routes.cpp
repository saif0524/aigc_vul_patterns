#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 405;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];
bool railway[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        railway[u][v] = railway[v][u] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!railway[i][j] && i!= j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    dist[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[n - 1] == -1) {
        cout << -1 << endl;
        return 0;
    }

    int ans = dist[n - 1];

    for (int i = 1; i < n; i++) {
        if (railway[0][i]) {
            ans = max(ans, 2);
            break;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        if (railway[i][n - 1]) {
            ans = max(ans, 2);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}