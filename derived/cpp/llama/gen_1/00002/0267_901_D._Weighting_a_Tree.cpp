#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int c[MAXN];
int deg[MAXN];
int res[MAXN];

void dfs(int v, int p, int& global_flow, vector<char>& used) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        dfs(to, v, global_flow, used);
        if (res[to] == 0) {
            res[to] = 1;
            res[v] -= 1;
            global_flow += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    vector<char> used(n + 1);
    int global_flow = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            dfs(i, 0, global_flow, used);
        }
    }

    if (global_flow != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        res[i] = c[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int to : g[i]) {
            if (i < to) {
                cout << res[i] << "\n";
                res[to] -= res[i];
                res[i] = 0;
            }
        }
    }

    return 0;
}