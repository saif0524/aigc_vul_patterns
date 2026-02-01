#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t >> k;

    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<long long>> dp(t + 1, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[0][i] = a[i];
    }

    long long ans = 0;
    for (int i = 1; i <= t; i++) {
        vector<long long> cur(n);
        for (int j = 0; j < n; j++) {
            cur[j] = dp[i - 1][j] + b[j];
        }

        long long need = 0;
        for (int j = 0; j < n; j++) {
            if (cur[j] > c[j]) {
                need = LLONG_MAX;
                break;
            }
            need += max(0LL, cur[j]);
        }

        long long use = (need + k - 1) / k;
        ans += use;

        vector<long long> left(n);
        for (int j = 0; j < n; j++) {
            left[j] = max(0LL, cur[j] - use * k);
            if (j > 0) {
                left[j] = max(left[j], left[j - 1]);
            }
        }

        for (int j = 0; j < n; j++) {
            dp[i][j] = left[j];
        }
    }

    cout << ans << endl;
    return 0;
}