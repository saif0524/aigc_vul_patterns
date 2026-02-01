#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> g[N];
int color[N];
bool bad = false;

void dfs(int u, int c) {
    color[u] = c;
    for (auto v : g[u]) {
        if (color[v] == c) {
            bad = true;
            return;
        }
        if (color[v] == -1) dfs(v, c ^ 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        g[edges[i].first - 1].push_back(edges[i].second - 1);
        g[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) dfs(i, 0);
    }

    if (bad) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    string ans;
    for (auto e : edges) {
        if (color[e.first - 1] == 0) ans.push_back('0');
        else ans.push_back('1');
    }
    cout << ans << "\n";

    return 0;
}