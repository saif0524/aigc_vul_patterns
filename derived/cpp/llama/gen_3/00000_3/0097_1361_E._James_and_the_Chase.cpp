#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN], rev_adj[MAXN];
bool visited[MAXN], rev_visited[MAXN];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void rev_dfs(int u, vector<int>& path) {
    rev_visited[u] = true;
    path.push_back(u);
    for (int v : rev_adj[u]) {
        if (!rev_visited[v]) {
            rev_dfs(v, path);
        }
    }
}

bool is_interesting(int u) {
    vector<int> path;
    rev_dfs(u, path);
    return path.size() == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            rev_adj[i].clear();
            visited[i] = false;
            rev_visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        int interesting_cnt = 0;
        vector<int> interesting_cities;

        for (int i = 1; i <= n; i++) {
            if (is_interesting(i)) {
                interesting_cnt++;
                interesting_cities.push_back(i);
            }
        }

        if (interesting_cnt < 0.2 * n) {
            cout << "-1\n";
        } else {
            sort(interesting_cities.begin(), interesting_cities.end());
            for (int city : interesting_cities) {
                cout << city << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}