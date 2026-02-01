#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 50, M = 100000, MOD = 1000000007;

int n, m;
vector<int> adj[N], vision[N][N];
int vis[2 * N + 1][N];
vector<int> path;

void find_path(int u, int len) {
    if (len >= 2 * n) return;
    vis[len][u] = 1;
    path.push_back(u);
    if (len > 0) {
        for (int v : adj[u]) {
            if (vis[len - 1][v]) {
                cout << len + 1 << endl;
                for (int i = 0; i <= len; i++) cout << path[i] << " ";
                cout << v << endl;
                exit(0);
            }
        }
    }
    for (int v : adj[u]) {
        vector<int> temp = vision[u][v];
        for (int w : temp) {
            if (vis[len][w]) {
                cout << len + 2 << endl;
                for (int i = 0; i <= len; i++) cout << path[i] << " ";
                cout << u << " " << v << endl;
                exit(0);
            }
        }
    }
    for (int v : adj[u]) {
        if (!vis[len + 1][v]) find_path(v, len + 1);
    }
    vis[len][u] = 0;
    path.pop_back();
}

int dfs(int u, int len, int goal) {
    if (len == goal) {
        for (int v : adj[u]) {
            if (vision[u][v].size() == goal && vision[u][v][goal - 1] == u) {
                return 1;
            }
        }
        return 0;
    }
    int ret = 0;
    for (int v : adj[u]) {
        for (int j = 0; j < vision[u][v].size(); j++) {
            if (vision[u][v][j] == u) {
                ret = (ret + dfs(v, len + 1, goal)) % MOD;
            }
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        adj[u].push_back(v);
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            vision[u][v].push_back(x);
        }
    }
    bool found = false;
    for (int i = 0; i < n; i++) {
        path.clear();
        find_path(i, 0);
    }
    if (!found) cout << 0 << endl;
    for (int i = 1; i <= 2 * n; i++) {
        int ret = 0;
        for (int j = 0; j < n; j++) {
            ret = (ret + dfs(j, 1, i)) % MOD;
        }
        cout << ret << endl;
    }
    return 0;
}