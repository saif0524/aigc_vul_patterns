#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i - 1] * i, dp[i - 1][1] + a[i - 1] * i);
        dp[i][1] = max(dp[i - 1][0] + b[i - 1] * i, dp[i - 1][1] + b[i - 1] * i);
    }

    long long ans = max(dp[n][0], dp[n][1]);

    vector<vector<long long>> dp2(n + 1, vector<long long>(2, 0));
    dp2[0][0] = 0;
    dp2[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        dp2[i][0] = max(dp2[i - 1][0] + a[n - i] * i, dp2[i - 1][1] + a[n - i] * i);
        dp2[i][1] = max(dp2[i - 1][0] + b[n - i] * i, dp2[i - 1][1] + b[n - i] * i);
    }

    ans = max(ans, max(dp2[n][0], dp2[n][1]));

    cout << ans << endl;

    return 0;
}