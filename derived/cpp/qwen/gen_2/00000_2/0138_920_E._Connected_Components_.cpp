#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool visited[200005];
int component_size;

void dfs(int v) {
    visited[v] = true;
    component_size++;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> component_sizes;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            component_size = 0;
            dfs(i);
            component_sizes.push_back(component_size);
        }
    }
    sort(component_sizes.begin(), component_sizes.end());
    cout << component_sizes.size() << "\n";
    for (int size : component_sizes) {
        cout << size << " ";
    }
    cout << "\n";
}