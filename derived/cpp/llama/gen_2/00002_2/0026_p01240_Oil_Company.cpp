#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int W, H;
        cin >> W >> H;

        vector<vector<int>> grid(H, vector<int>(W));
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                cin >> grid[j][k];
            }
        }

        vector<vector<int>> dp(H, vector<int>(W, 0));
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                int maxVal = 0;
                if (j == 0 && k == 0) {
                    maxVal = grid[j][k];
                } else if (j == 0) {
                    maxVal = max(dp[j][k-1], grid[j][k]);
                } else if (k == 0) {
                    maxVal = max(dp[j-1][k], grid[j][k]);
                } else {
                    maxVal = max(dp[j-1][k], dp[j][k-1]);
                    if (j > 0 && k > 0) {
                        maxVal = max(maxVal, dp[j-1][k-1] + grid[j][k]);
                    }
                    if (j > 0 && k < W - 1) {
                        maxVal = max(maxVal, dp[j-1][k+1] + grid[j][k]);
                    }
                }
                dp[j][k] = maxVal;
            }
        }

        int maxVal = 0;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                maxVal = max(maxVal, dp[j][k]);
            }
        }

        cout << "Case " << i + 1 << ": " << maxVal << endl;
    }

    return 0;
}