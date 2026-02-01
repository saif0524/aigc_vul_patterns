#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 200005;

int n, k;
vector<int> g[N];
int d[N], p[N], c[N];

void dfs(int v, int par = -1) {
    for (int u : g[v]) {
        if (u == par) continue;
        d[u] = d[v] + 1;
        p[u] = v;
        dfs(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int v1 = 1;
    for (int i = 2; i <= n; i++) {
        if (g[i].size() == 1) {
            v1 = i;
            break;
        }
    }

    dfs(v1);

    int v2 = 1;
    for (int i = 2; i <= n; i++) {
        if (d[i] > d[v2]) {
            v2 = i;
        }
    }

    dfs(v2);

    int v3 = 1;
    for (int i = 2; i <= n; i++) {
        if (d[i] > d[v3]) {
            v3 = i;
        }
    }

    vector<int> path;
    for (int v = v3; v!= v2; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(v2);

    if (path.size() < k) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        c[i] = -1;
    }

    for (int i = 0; i < path.size(); i++) {
        c[path[i]] = i % k + 1;
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] == -1) {
            c[i] = 1;
        }
        cout << c[i] << " ";
    }
    cout << "\n";

    return 0;
}