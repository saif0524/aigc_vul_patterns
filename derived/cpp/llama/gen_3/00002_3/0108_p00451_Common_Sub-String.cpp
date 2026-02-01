#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}