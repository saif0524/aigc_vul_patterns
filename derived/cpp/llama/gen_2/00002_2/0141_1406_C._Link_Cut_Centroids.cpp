#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj[MAX_N];
int parent[MAX_N];

void dfs(int u, int p) {
    parent[u] = p;
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        if (adj[1].size() > 1) {
            cout << 1 << " " << adj[1][0] << "\n";
            cout << 1 << " " << adj[1][1] << "\n";
        } else {
            cout << 1 << " " << adj[1][0] << "\n";
            cout << 1 << " " << adj[1][0] << "\n";
        }
    }

    return 0;
}