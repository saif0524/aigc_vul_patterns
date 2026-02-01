#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, m;
int p[MAXN];
vector<int> adj[MAXN];

int dfs(int u, int depth) {
    int max_depth = depth;
    for (int v : adj[u]) {
        max_depth = max(max_depth, dfs(v, depth + 1));
    }
    return max_depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }

    int last = n - 1;
    for (int i = 0; i < n; ++i) {
        if (p[i] == n) {
            last = i;
            break;
        }
    }

    cout << dfs(last, 0) << '\n';

    return 0;
}