#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> r(n), c(n);
        for (int i = 0; i < n; ++i) cin >> r[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        vector<long long> dp(n, INT_MAX);
        long long ans = INT_MAX;

        auto dpf = [&](long long dp[], int i, long long cost) {
            if (dp[i] <= cost) return;
            dp[i] = cost;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long ncost = cost + (abs(r[i] - r[j]) + abs(c[i] - c[j])) / 2;
                if ((r[i] + c[i]) % 2 == (r[j] + c[j]) % 2) ncost++;
                if (ncost < dp[j]) dpf(dp, j, ncost);
            }
        };

        for (int i = 0; i < n; ++i) {
            fill(dp.begin(), dp.end(), INT_MAX);
            long long cost = (r[i] - 1 + c[i] - 1) / 2;
            if ((1 + 1) % 2 != (r[i] + c[i]) % 2) cost++;
            dpf(dp, i, cost);
            long long sum = 0;
            for (int j = 0; j < n; ++j) sum += dp[j];
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}