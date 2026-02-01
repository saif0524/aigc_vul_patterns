#include <iostream>
#include <vector>

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

    vector<vector<long long>> dp(n, vector<long long>(MAX + 1, 0));
    vector<vector<long long>> sum(n, vector<long long>(MAX + 1, 0));

    for (int j = 1; j <= MAX; j++) {
        dp[0][j] = (a[0] == -1 || a[0] == j);
        sum[0][j] = dp[0][j] + (j > 1 ? sum[0][j - 1] : 0);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= MAX; j++) {
            if (a[i] != -1 && a[i] != j) {
                dp[i][j] = 0;
                continue;
            }

            if (i == n - 1) {
                dp[i][j] = (j >= (a[i - 1] == -1 ? 1 : a[i - 1])) ? sum[i - 1][j] : 0;
            } else {
                dp[i][j] = sum[i - 1][j];
                if (j > (a[i - 1] == -1 ? 1 : a[i - 1])) {
                    dp[i][j] = (dp[i][j] + sum[i - 1][a[i - 1] == -1 ? j - 1 : a[i - 1] - 1]) % MOD;
                }
            }
        }

        for (int j = 1; j <= MAX; j++) {
            sum[i][j] = (dp[i][j] + (j > 1 ? sum[i][j - 1] : 0)) % MOD;
        }
    }

    long long ans = sum[n - 1][MAX];
    cout << ans << endl;

    return 0;
}