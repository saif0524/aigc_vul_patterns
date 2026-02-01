#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSouvenirs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
        return 0;
    }

    if (dp[r][c] != -1) {
        return dp[r][c];
    }

    int maxVal = grid[r][c];
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (auto& dir : dirs) {
        int nr = r + dir.first;
        int nc = c + dir.second;
        maxVal = max(maxVal, grid[r][c] + maxSouvenirs(grid, nr, nc, dp));
    }

    dp[r][c] = maxVal;
    return maxVal;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(H, vector<int>(W, -1));
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            ans = max(ans, maxSouvenirs(grid, i, j, dp));
        }
    }

    cout << ans << endl;

    return 0;
}