#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    uint64_t dp[n + 1][n * a + 1] = {};

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * a; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1]) {
                dp[i][j] += dp[i - 1][j - v[i - 1]];
            }
        }
    }

    uint64_t ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i * a <= n * a) {
            ans += dp[n][i * a];
        }
    }

    cout << ans << endl;

    return 0;
}