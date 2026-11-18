#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int k;
    cin >> k;
    vector<int> c(k);
    int total = 0;
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        total += c[i];
    }

    vector<vector<long long>> dp(total + 1, vector<long long>(k + 1, 0));
    dp[0][0] =1;

    for (int i = 1; i <= total; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (c[j - 1] >0 && i >= c[j - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - c[j -1]][j - 1]) % MOD;
            }
        }
    }

    cout << dp[total][k] << endl;
    return 0;
}