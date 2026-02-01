#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a][b] = graph[b][a] = c;
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != -1) {
                cnt++;
            }
        }
        if (cnt == 0) {
            ans = (ans * 2) % MOD;
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 0) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (graph[i][k] == 1 && graph[j][k] == 1) {
                        cnt++;
                    }
                }
                if (cnt > 0) {
                    ok = false;
                }
            } else if (graph[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if ((graph[i][k] == 0 && graph[j][k] == 0) || (graph[i][k] == 1 && graph[j][k] == 1)) {
                        cnt++;
                    }
                }
                if (cnt < n) {
                    ok = false;
                }
            }
        }
    }

    if (!ok) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}