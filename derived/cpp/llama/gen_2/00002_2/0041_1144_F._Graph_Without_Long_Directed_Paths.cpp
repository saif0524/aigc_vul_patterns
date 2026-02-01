#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> g[MAXN];
vector<pair<int, int>> edges;
int n, m;
int deg[MAXN];
bool isStar = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] > 1) {
            isStar = false;
            break;
        }
    }

    if (!isStar) {
        cout << "NO\n";
        return 0;
    }

    string ans;
    for (auto& [u, v] : edges) {
        if (deg[u] == 1) {
            ans.push_back('0');
        } else {
            ans.push_back('1');
        }
        deg[v]--;
    }

    cout << "YES\n" << ans << '\n';
    return 0;
}