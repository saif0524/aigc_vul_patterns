#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] = g[b][a] = c;
    }

    for (int i = 0; i < n; i++) {
        if (g[i][i]!= -1) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 1;
    int cnt = 0;
    vector<int> comp(n, -1);
    vector<int> sz(n, 0);

    for (int i = 0; i < n; i++) {
        if (comp[i]!= -1) continue;

        vector<int> q;
        q.push_back(i);
        comp[i] = cnt;
        int s = 0;
        int x = 0;
        while (!q.empty()) {
            int u = q.back();
            q.pop_back();
            s += 1;
            for (int v = 0; v < n; v++) {
                if (g[u][v]!= -1) {
                    if (comp[v]!= -1 && comp[v]!= comp[u]) {
                        cout << 0 << endl;
                        return 0;
                    }
                    if (comp[v] == -1) {
                        comp[v] = comp[u];
                        q.push_back(v);
                    }
                } else {
                    x += 1;
                }
            }
        }

        if (s == 1) {
            ans = (ans * 2) % MOD;
        } else {
            ans = (ans * (1 + (1LL << (x - s))) % MOD) % MOD;
        }

        sz[cnt] = s;
        cnt += 1;
    }

    if (cnt == 1) {
        ans = (ans - 2 + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}