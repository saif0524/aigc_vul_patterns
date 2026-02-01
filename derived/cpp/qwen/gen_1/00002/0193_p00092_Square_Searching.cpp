#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n != 0) {
        vector<vector<int>> grid(n, vector<int>(n));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int max_side = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                grid[i][j] = (s[j] == '*');
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!grid[i-1][j-1]) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        cout << max_side << "\n";
    }
    return 0;
}