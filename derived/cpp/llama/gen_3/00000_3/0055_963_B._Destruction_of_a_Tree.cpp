#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int deg[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x) {
            g[x].push_back(i);
            g[i].push_back(x);
        }
    }

    for (int i = 1; i <= n; ++i) {
        deg[i] = g[i].size();
    }

    queue<int> q;
    vector<int> ans;
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            q.push(i);
            vis[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : g[u]) {
            if (vis[v]) continue;
            --deg[v];
            if (!deg[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && deg[i] % 2 == 0) {
            ans.push_back(i);
        }
    }

    if (ans.size() != n) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}