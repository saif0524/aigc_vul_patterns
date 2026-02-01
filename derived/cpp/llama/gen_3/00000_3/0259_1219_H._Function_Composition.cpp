#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 2e5 + 5;

int a[MAX_N];
map<int, vector<int>> cycle;
vector<int> len, -, in;

int dfs(int u, int p, int d) {
    if (in[u]) return len[u];
    in[u] = d;
    int v = a[u];
    if (in[v] < 0) {
        len[u] = dfs(v, u, d + 1);
    } else if (in[v] < in[u]) {
        len[u] = in[u] - in[v];
    } else {
        len[u] = -1;
    }
    in[u] = -1;
    return len[u];
}

void dfs2(int u, int p) {
    if (cycle.find(u) != cycle.end()) return;
    int v = a[u];
    if (cycle.find(v) == cycle.end()) dfs2(v, u);
    cycle[u] = cycle[v];
    cycle[u].push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0, 1);
        dfs2(i, 0);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long m;
        int y;
        cin >> m >> y;
        int ans = 0;
        for (int x = 1; x <= n; x++) {
            if (cycle.find(x) == cycle.end()) continue;
            if (cycle[x].back() != cycle[y].back()) continue;
            int l = m % len[x];
            auto it = lower_bound(cycle[x].begin(), cycle[x].end(), l + cycle[x].front());
            int v = cycle[x][it - cycle[x].begin()];
            if (v == y) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}