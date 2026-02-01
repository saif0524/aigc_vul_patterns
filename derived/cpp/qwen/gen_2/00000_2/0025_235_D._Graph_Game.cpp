#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n;

double dfs(int u, int p) {
    visited[u] = true;
    int size = 1;
    vector<int> component_sizes;
    for (int v : adj[u]) {
        if (v != p && !visited[v]) {
            component_sizes.push_back(dfs(v, u));
            size += component_sizes.back();
        }
    }
    double res = size;
    for (int s : component_sizes) {
        res += (double)s / (size - 1) * dfs(v, u);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.resize(n, false);
    double result = dfs(0, -1);
    cout << setprecision(15) << fixed << result << "\n";
}