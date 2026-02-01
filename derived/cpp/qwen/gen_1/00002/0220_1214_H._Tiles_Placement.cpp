#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
int color[N];
bool visited[N];
int n, k;

bool dfs(int node, int curr_color) {
    color[node] = curr_color;
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (!dfs(neighbor, (curr_color % k) + 1)) {
                return false;
            }
        } else if (color[neighbor] == curr_color) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (dfs(1, 1)) {
        cout << "Yes\n";
        for (int i = 1; i <= n; ++i) {
            cout << color[i] << (i == n ? '\n' : ' ');
        }
    } else {
        cout << "No\n";
    }
    return 0;
}