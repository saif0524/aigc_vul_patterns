#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            dp[i + 1][1 - j] = (dp[i + 1][1 - j] + dp[i][j]) % MOD;
        }

        if (i > 0 && s[i] == s[i - 1]) {
            dp[i + 1][s[i] - 'a'] = (dp[i + 1][s[i] - 'a'] - dp[i - 1][1 - (s[i] - 'a')] + MOD) % MOD;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;

    return 0;
}