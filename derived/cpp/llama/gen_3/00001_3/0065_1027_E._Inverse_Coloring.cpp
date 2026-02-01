#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    if (k > n * n) {
        cout << powmod(2, n * n) << '\n';
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = add(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cnt++;
        }

        if (cnt * cnt >= k) continue;

        ans = add(ans, mul(dp[n][cnt & 1], dp[n][cnt & 1]));
    }

    cout << ans << '\n';

    return 0;
}