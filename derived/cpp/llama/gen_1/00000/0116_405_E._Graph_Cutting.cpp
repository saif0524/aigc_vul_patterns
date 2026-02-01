#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> g[MAXN];
bool used[MAXN];

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << "No solution" << endl;
            return 0;
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (g[a].size() < g[b].size()) {
            swap(a, b);
        }
        bool found = false;
        for (int j = 0; j < g[b].size(); j++) {
            int c = g[b][j];
            if (c != a && g[c].size() <= g[b].size()) {
                ans.push_back({a, b, c});
                g[a].erase(remove(g[a].begin(), g[a].end(), b), g[a].end());
                g[b].erase(remove(g[b].begin(), g[b].end(), a), g[b].end());
                g[c].erase(remove(g[c].begin(), g[c].end(), b), g[c].end());
                g[b].erase(remove(g[b].begin(), g[b].end(), c), g[b].end());
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No solution" << endl;
            return 0;
        }
    }

    if (ans.size() * 2 != m) {
        cout << "No solution" << endl;
        return 0;
    }

    for (const auto& path : ans) {
        cout << path[0] << " " << path[1] << " " << path[2] << endl;
    }

    return 0;
}