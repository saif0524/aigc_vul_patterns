#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAX = 200;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(MAX + 1, 0));
    if (a[0] == -1) {
        for (int i = 1; i <= MAX; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == -1) {
            for (int j = 1; j <= MAX; j++) {
                for (int k = j; k <= MAX; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        } else {
            for (int j = 1; j <= MAX; j++) {
                if (j <= a[i]) {
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][j]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    if (a[n - 1] == -1) {
        for (int i = 1; i <= MAX; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
    } else {
        ans = dp[n - 1][a[n - 1]];
    }

    cout << ans << endl;

    return 0;
}