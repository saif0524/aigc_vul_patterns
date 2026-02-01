#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int id[N];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            id[v] = u;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        visited[i] = false;
        id[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (id[i] == 0) {
            ans.push_back(i);
        }
    }
    bool ok = true;
    for (int i = 0; i < ans.size(); ++i) {
        int u = ans[i];
        for (int j = 1; j <= n; ++j) {
            if (u == j) {
                continue;
            }
            visited[j] = false;
        }
        int cnt = 0;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
                ++cnt;
            }
        }
        if (cnt > 1) {
            ok = false;
            break;
        }
    }
    if (ans.size() * 5 < n || !ok) {
        cout << -1 << endl;
        return;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}