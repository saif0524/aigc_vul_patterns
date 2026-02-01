#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int l = -1;
    for (int i = 0; i < n; i++) {
        if ((int)g[i].size() == 1) {
            l = i;
            break;
        }
    }

    if (l!= -1) {
        cout << g[l][0] + 1 << ' ' << l + 1 << '\n';
        cout << 0 + 1 << ' ' << l + 1 << '\n';
        return;
    }

    int cnt = 0;
    int r = -1;
    for (int i = 0; i < n; i++) {
        if ((int)g[i].size() > 1) {
            if (cnt == 0) {
                r = i;
                cnt++;
            } else {
                cout << r + 1 << ' ' << g[r][0] + 1 << '\n';
                cout << i + 1 << ' ' << g[i][0] + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}