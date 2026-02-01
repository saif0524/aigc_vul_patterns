#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 55;

int n, m;
vector<pair<int, int>> ans;
vector<int> deg[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : deg[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u].push_back(v);
        deg[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i].size() > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i].empty()) {
            ans.emplace_back(i, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i].size() == 1) {
            for (int j = i + 1; j <= n; j++) {
                if (deg[j].size() == 1) {
                    ans.emplace_back(i, j);
                    deg[i].push_back(j);
                    deg[j].push_back(i);
                    break;
                }
            }
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (auto& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}