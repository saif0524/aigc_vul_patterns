#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e18
#define MOD 1000000007

const int N = 1e5 + 5;

int n, m, d[N], u[N], v[N];
vector<int> g[N];
vector<int> c[N];
bool vis[N];
int col[N];

int dfs(int u, int p) {
    vis[u] = true;
    col[u] = col[p] ^ 1;

    for (auto v : g[u]) {
        if (vis[v]) {
            if (col[u] == col[v]) {
                return -1;
            }
        } else {
            if (dfs(v, u) == -1) {
                return -1;
            }
        }
    }

    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        c[u[i]].push_back(i);
        c[v[i]].push_back(i);
    }

    col[1] = 0;
    int ok = dfs(1, 1);

    if (ok == -1) {
        cout << "-1\n";
        return 0;
    }

    int res = INF;
    for (int i = 1; i <= n; ++i) {
        if (col[i] == 0) {
            res = min(res, d[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (col[i] == 0) {
            d[i] -= res;
        }
    }

    vector<vector<int> > a(n + 1);
    vector<vector<int> > b(n + 1);
    vector<vector<int> > e(m + 1);

    for (int i = 1; i <= m; ++i) {
        int u = ::u[i], v = ::v[i];
        e[i] = {min(d[u], d[v]), max(d[u], d[v]), u, v, 0};
    }

    sort(e.begin() + 1, e.begin() + m + 1);

    for (int i = 1; i <= m; ++i) {
        int u = e[i][2], v = e[i][3], w = e[i][0];

        if (d[u] > w) {
            d[u] -= w;
            a[u].push_back(i);
        } else {
            b[u].push_back(i);
        }

        if (d[v] > w) {
            d[v] -= w;
            a[v].push_back(i);
        } else {
            b[v].push_back(i);
        }

        e[i][4] = w;
    }

    string s;
    for (int i = 1; i <= n; ++i) {
        if (col[i] == 0) {
            s += 'W';
        } else {
            s += 'B';
        }
    }

    cout << s << "\n";
    for (int i = 1; i <= m; ++i) {
        cout << e[i][4] << "\n";
    }

    return 0;
}