#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
int grid[MAXN][MAXN];
int memo[MAXN][MAXN][2]; // 2 for not taken, 1 for taken
int w, h;

int dp(int i, int j, bool taken) {
    if (i >= h) return 0;
    if (j >= w) return dp(i + 1, 0, 0);
    int& ret = memo[i][j][taken];
    if (ret != -1) return ret;

    int exclude = dp(i, j + 1, taken);
    int include = 0;
    if (!taken && (i == 0 || j == 0 || grid[i - 1][j - 1] == 0)) {
        include = grid[i][j] + dp(i, j + 1, 1);
    }
    return ret = max(include, exclude);
}

int solve() {
    memset(memo, -1, sizeof memo);
    return dp(0, 0, 0);
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> w >> h;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
            }
        }
        int ans = solve();
        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}