#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, m;
int p[N], t[N], s[N], on_vacation[N];
vector<int> g[N];
int ans[N];

void dfs(int v, int parent) {
    s[v] = 0;
    for (int u : g[v]) {
        dfs(u, v);
        s[v] += s[u] + 1;
    }
}

void dfs2(int v, int parent) {
    int cnt = 0;
    for (int u : g[v]) {
        if (!on_vacation[u]) {
            cnt++;
        }
    }
    if (cnt > t[v] &&!on_vacation[v]) {
        ans[m] += 1;
    }
    for (int u : g[v]) {
        dfs2(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            on_vacation[x] = 1;
        } else {
            on_vacation[-x] = 0;
        }
        ans[i] = 0;
        dfs2(1, 0);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}