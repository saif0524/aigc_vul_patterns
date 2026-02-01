#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        double dp[n+1];
        dp[0] = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1.0 + 0.5 * dp[i-1];
        }
        cout << fixed << setprecision(8) << dp[n] << "\n";
    }
    return 0;
}