#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> g[MAXN];
int a[MAXN];
int dp[MAXN];

int dfs(int v, int p = -1) {
    int res = a[v];
    for (int u : g[v]) {
        if (u!= p) {
            res += dfs(u, v);
        }
    }
    return dp[v] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << dfs(1) << endl;

    return 0;
}