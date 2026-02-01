#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < n; ++j) {
                if (line[j] == '*') grid[i][j] = true;
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int max_side = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        cout << max_side << endl;
    }
    return 0;
}