#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

vector<int> g[MAX_N];
int n, k;
int colors[MAX_N];
int d[MAX_N];

void dfs(int v, int pr, int depth) {
    d[v] = depth;
    for (int to : g[v]) {
        if (to != pr) {
            dfs(to, v, depth + 1);
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1, 0);

    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == k - 1) {
            f = i;
            break;
        }
    }

    if (!f) {
        cout << "No" << endl;
        return;
    }

    colors[f] = 0;
    int ind = 1;
    for (int to : g[f]) {
        vector<int> path;
        path.push_back(f);
        int tmp = to;
        while (true) {
            path.push_back(tmp);
            if (d[tmp] == 0) break;
            for (int x : g[tmp]) {
                if (d[x] < d[tmp]) {
                    tmp = x;
                    break;
                }
            }
        }
        for (int j = 0; j < path.size(); ++j) {
            colors[path[j]] = j % k;
        }
        ind += path.size() - 1;
        if (ind > n) break;
    }

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            colors[i] = f % k;
            ++f;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        cout << colors[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}