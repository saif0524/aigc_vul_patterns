#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int test = 1; test <= N; ++test) {
        int W, H;
        cin >> W >> H;
        vector<vector<int>> grid(H, vector<int>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<vector<int>> dp(H, vector<int>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                int value = grid[i][j];
                if (i > 0) value = max(value, dp[i - 1][j]);
                if (j > 0) value = max(value, dp[i][j - 1]);
                if (i > 0 && j > 0) value = max(value, dp[i - 1][j - 1]);
                if (i > 0 && j < W - 1) value = max(value, dp[i - 1][j + 1]);
                dp[i][j] = value + grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << "Case " << test << ": " << ans << "\n";
    }
    return 0;
}