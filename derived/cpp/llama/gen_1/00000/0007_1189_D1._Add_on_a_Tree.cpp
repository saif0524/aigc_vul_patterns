#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
int cnt = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    bool isLeaf = true;
    for (int u : g[v]) {
        if (u != p) {
            isLeaf = false;
            if (!used[u]) {
                dfs(u, v);
            }
        }
    }
    if (isLeaf) {
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    g.resize(n);
    used.resize(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    if ((cnt * (cnt - 1)) / 2 >= n - 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}