#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int low[MAXN], disc[MAXN], parent[MAXN];
int time = 0, bridges = 0;
bool visited[MAXN];

void dfs(int u) {
    disc[u] = low[u] = time++;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges++;
            }
        } else if (v!= parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (low[j] > disc[a] && low[j] > disc[b]) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}