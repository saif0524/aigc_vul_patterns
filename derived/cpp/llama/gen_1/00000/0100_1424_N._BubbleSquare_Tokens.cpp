#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 12505;
const int MAXK = 1000005;

int n, k;
vector<int> g[MAXN];
vector<pair<int, int>> edges;
int deg[MAXN];
set<int> s[MAXN];
int keep[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u, v);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        s[i].insert(deg[i] * 2 + 1);
    }

    for (auto& [u, v] : edges) {
        int x = *s[u].begin();
        int y = *s[v].begin();
        int mn = min(x, y);
        int mx = max(x, y);
        s[u].erase(s[u].begin());
        s[v].erase(s[v].begin());
        s[u].insert(mx);
        s[v].insert(mn);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (*s[i].begin() == deg[i] * 2 + 1) {
            cnt++;
            keep[i] = 1;
        }
    }

    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (keep[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    for (auto& [u, v] : edges) {
        int x = *s[u].begin();
        int y = *s[v].begin();
        cout << u << ' ' << v << ' ' << min(x, y) / 2 - 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}