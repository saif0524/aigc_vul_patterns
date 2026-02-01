#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, m;
vector<int> G[N];
bool c[N];

bool dfs(int u, bool col) {
    c[u] = col;
    for (int v : G[u]) {
        if (c[v] == col) return false;
        if (!c[v] && !dfs(v, !col)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (!c[i] && !dfs(i, 0)) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "-1\n";
        return 0;
    }
    int cnt[2] = {0, 0};
    vector<int> a[2];
    for (int i = 1; i <= n; i++) {
        if (c[i] != -1) {
            a[c[i]].push_back(i);
            cnt[c[i]]++;
        }
    }
    cout << cnt[0] << "\n";
    for (int i : a[0]) cout << i << " ";
    cout << "\n" << cnt[1] << "\n";
    for (int i : a[1]) cout << i << " ";
    cout << "\n";
    return 0;
}