#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;

vector<int> adj[MAX_N];
int dist[MAX_N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

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
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;
    u--, v--;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(dist, dist + n, -1);
    bfs(u);

    int ans = dist[v];

    fill(dist, dist + n, -1);
    bfs(v);

    for (int i = 0; i < n; i++) {
        if (dist[i] == ans && i!= v) {
            ans = min(ans, dist[u] + 1);
            break;
        }
    }

    cout << ans / 2 << endl;

    return 0;
}