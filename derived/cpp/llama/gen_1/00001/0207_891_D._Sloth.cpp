#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;

int n;
vector<int> g[MAXN];
long long dp[MAXN][2][2];

void dfs(int v, int p) {
    dp[v][0][0] = 1;
    dp[v][1][1] = 1;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v);
            long long ndp[2][2] = {{0, 0}, {0, 0}};
            ndp[0][0] = (dp[v][0][0] * dp[u][1][0] + dp[v][0][0] * dp[u][1][1] + dp[v][0][1] * dp[u][0][0] + dp[v][0][1] * dp[u][1][0]) % MOD;
            ndp[1][1] = (dp[v][1][1] * dp[u][0][1] + dp[v][1][1] * dp[u][0][0] + dp[v][1][0] * dp[u][1][1] + dp[v][1][0] * dp[u][0][1]) % MOD;
            ndp[0][1] = (dp[v][0][0] * dp[u][0][1] + dp[v][0][1] * dp[u][1][1]) % MOD;
            ndp[1][0] = (dp[v][1][1] * dp[u][1][0] + dp[v][1][0] * dp[u][0][0]) % MOD;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    dp[v][i][j] = ndp[i][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    long long ans = 0;
    for (int v = 0; v < n; v++) {
        ans += dp[v][1][0];
    }
    cout << ans % MOD << endl;
    return 0;
}