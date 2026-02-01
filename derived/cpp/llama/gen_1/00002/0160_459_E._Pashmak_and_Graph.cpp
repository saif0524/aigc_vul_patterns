#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;

struct Edge {
    int to, w;
};

vector<Edge> g[N];
vector<int> w, p;
int f[N], ans;

void dfs(int v) {
    if (f[v] != -1) return;
    f[v] = 0;
    for (auto& e : g[v]) {
        dfs(e.to);
        if (e.w > p[v] && f[e.to] + 1 > f[v]) {
            f[v] = f[e.to] + 1;
        }
    }
    ans = max(ans, f[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, wi;
        cin >> u >> v >> wi;
        g[u].push_back({v, wi});
        w.push_back(wi);
    }

    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());

    for (int i = 1; i <= n; ++i) {
        p.push_back(-1);
        f[i] = -1;
        for (auto& e : g[i]) {
            int idx = lower_bound(w.begin(), w.end(), e.w) - w.begin();
            e.w = idx;
            p[i] = max(p[i], idx - 1);
        }
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }

    cout << ans << '\n';

    return 0;
}