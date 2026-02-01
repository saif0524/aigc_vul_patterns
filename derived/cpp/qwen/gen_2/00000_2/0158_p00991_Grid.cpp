#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int main() {
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;
    
    int dr = min(abs(a1 - b1), r - abs(a1 - b1));
    int dc = min(abs(a2 - b2), c - abs(a2 - b2));
    
    vector<vector<int>> dp(dr + 1, vector<int>(dc + 1));
    dp[0][0] = 1;
    
    for (int i = 0; i <= dr; ++i) {
        for (int j = 0; j <= dc; ++j) {
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    
    cout << dp[dr][dc] << endl;
    
    return 0;
}