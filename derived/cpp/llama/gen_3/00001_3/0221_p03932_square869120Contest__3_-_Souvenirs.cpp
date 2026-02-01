#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (int j = 0; j < w; j++) {
        dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + grid[i][j];
            } else if (j == w - 1) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + grid[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + grid[i][j];
            }
        }
    }

    cout << *max_element(dp[h - 1].begin(), dp[h - 1].end());

    return 0;
}