#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> g[N];
int h[N], up[N], n, k, cnt;

void dfs(int v, int p = -1) {
    h[v] = (p == -1 ? 0 : h[p] + 1);
    up[v] = v;
    if (g[v].empty()) {
        cnt++;
        return;
    }
    for (int u : g[v]) {
        dfs(u, v);
        if (h[up[u]] > h[up[v]]) {
            up[v] = up[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    dfs(0);
    int ans = 0;
    for (int v = 0; v < n; v++) {
        if (g[v].empty()) {
            int u = v;
            int tmp = 1;
            for (int i = 0; i < k; i++) {
                u = (u ? (g[u][0] == v ? g[u][1] : g[u][0]) : -1);
                if (u == -1) break;
                if (g[u].empty()) tmp++;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}