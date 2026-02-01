#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdint>

using namespace std;

const int MAX = 101;

int64_t dp[MAX][MAX][MAX][MAX];

int64_t go(int n, int m, int k, int mod, int x, int y, int val) {
    if (x == n) {
        return 1;
    }
    if (y == m) {
        return go(n, m, k, mod, x + 1, 0, val);
    }
    int64_t& ret = dp[x][y][n][m];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= k; ++i) {
        ret = (ret + go(n, m, k, mod, x, y + 1, min(val, i))) % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, mod;
    cin >> n >> m >> k >> mod;

    fill_n(&dp[0][0][0][0], MAX * MAX * MAX * MAX, -1);

    int64_t ans = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            ans = (ans + go(n, m, k, mod, 0, 0, min(i, j))) % mod;
        }
    }

    cout << ans << '\n';

    return 0;
}