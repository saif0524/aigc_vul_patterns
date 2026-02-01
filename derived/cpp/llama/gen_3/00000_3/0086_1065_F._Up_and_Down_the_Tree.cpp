#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> adj[N];
int depth[N];

void dfs(int u, int p, int d) {
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int n, k;

bool isLeaf(int u) {
    return adj[u].size() == 1 && u != 1;
}

void solve() {
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1, 0, 0);
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        if (isLeaf(u)) {
            int cnt = 0;
            int v = u;
            for (int j = 0; j <= k && v != 1; j++) {
                v = adj[v][0];
                for (int w : adj[v]) {
                    if (isLeaf(w)) {
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}