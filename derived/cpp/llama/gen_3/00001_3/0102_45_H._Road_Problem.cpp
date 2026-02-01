#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

vector<int> g[MAXN];
bool used[MAXN];
int tin[MAXN], fup[MAXN];
int timer;
vector<int> bridges;
vector<pair<int, int>> ans;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                bridges.push_back(to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    if (bridges.empty()) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int to : g[i]) {
            deg[i]++;
        }
    }

    vector<int> leaves;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            leaves.push_back(i);
        }
    }

    if (leaves.size() <= 2) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < leaves.size(); i++) {
        for (int j = i + 1; j < leaves.size(); j++) {
            int a = leaves[i], b = leaves[j];
            if (find(g[a].begin(), g[a].end(), b) == g[a].end()) {
                ans.push_back({a, b});
            }
        }
    }

    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    return 0;
}