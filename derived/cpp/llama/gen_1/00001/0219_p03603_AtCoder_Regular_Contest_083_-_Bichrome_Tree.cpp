#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

vector<int> g[MAXN];
int x[MAXN], p[MAXN];
bool visited[MAXN];
long long total[MAXN];

void dfs(int u) {
    visited[u] = true;
    total[u] = x[u];
    for (auto v : g[u]) {
        if (!visited[v]) {
            dfs(v);
            total[u] += total[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (x[i] > total[i] || (total[i] - x[i]) % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";
}