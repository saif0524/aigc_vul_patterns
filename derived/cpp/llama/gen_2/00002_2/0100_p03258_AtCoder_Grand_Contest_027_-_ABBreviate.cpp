#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
            dp[i + 1][1] = dp[i][1];
        } else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;

    return 0;
}