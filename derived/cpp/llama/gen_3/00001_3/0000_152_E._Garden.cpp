#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_N = 105;
const int MAX_M = 105;
const int MAX_K = 8;

int n, m, k;
int a[MAX_N][MAX_M];
int x[MAX_K], y[MAX_K];
int dp[MAX_K][1 << MAX_K];
int from[MAX_K][1 << MAX_K];
int ans = INT_MAX;
int res[MAX_N][MAX_M];

void dfs(int u, int mask) {
    if (dp[u][mask]!= -1) return;
    if (mask == (1 << k) - 1) {
        dp[u][mask] = 0;
        return;
    }
    dp[u][mask] = INT_MAX;
    for (int v = 0; v < k; v++) {
        if ((mask >> v) & 1) continue;
        int tmp = mask | (1 << v);
        dfs(v, tmp);
        int cost = dp[v][tmp];
        for (int i = min(x[u], x[v]); i <= max(x[u], x[v]); i++) {
            for (int j = min(y[u], y[v]); j <= max(y[u], y[v]); j++) {
                cost += a[i][j];
            }
        }
        if (cost < dp[u][mask]) {
            dp[u][mask] = cost;
            from[u][mask] = v;
        }
    }
}

void print(int u, int mask) {
    if (mask == (1 << k) - 1) return;
    int v = from[u][mask];
    int tmp = mask | (1 << v);
    for (int i = min(x[u], x[v]); i <= max(x[u], x[v]); i++) {
        for (int j = min(y[u], y[v]); j <= max(y[u], y[v]); j++) {
            res[i][j] = 1;
        }
    }
    print(v, tmp);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < k; i++) {
        dfs(i, 1 << i);
    }
    for (int i = 0; i < k; i++) {
        if (dp[i][(1 << k) - 1] < ans) {
            ans = dp[i][(1 << k) - 1];
        }
    }
    for (int i = 0; i < k; i++) {
        if (dp[i][(1 << k) - 1] == ans) {
            memset(res, 0, sizeof(res));
            print(i, (1 << k) - 1);
            break;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (res[i][j]) {
                cout << 'X';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}