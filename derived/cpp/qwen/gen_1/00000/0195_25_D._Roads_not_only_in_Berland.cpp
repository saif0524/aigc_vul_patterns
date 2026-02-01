#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> par;
vector<bool> visited;

void dfs(int u, int p) {
    visited[u] = true;
    par[u] = p;
    for (int v : adj[u]) {
        if (!visited[v] && v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n + 1);
    par.resize(n + 1, -1);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    vector<pair<int, int>> extra;
    for (int i = 2; i <= n; ++i) {
        if (par[adj[i][0]] != i) {
            extra.push_back({i, adj[i][0]});
        }
    }
    int cycles = extra.size();
    cout << cycles << "\n";
    for (auto [u, v] : extra) {
        int x = u, y = v;
        while (x != y) {
            if (x == 1 || visited[par[x]]) {
                swap(x, y);
            }
            visited[x] = true;
            x = par[x];
        }
        cout << u << " " << v << " " << u << " " << x << "\n";
    }
}