#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

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
    return (long long)a * b % MOD;
}

int binpow(int a, int b) {
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
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;

            if (len == 1) {
                dp[l][r] = 1;
                continue;
            }

            int sum = 0;

            for (int k = l; k < r; ++k) {
                sum = add(sum, mul(dp[l][k], dp[k + 1][r]));
            }

            dp[l][r] = add(1, sub(sum, dp[l][r - 1]));

            if (s[l] == s[r]) {
                dp[l][r] = add(dp[l][r], dp[l][r - 1]);
            }

            if (l + 1 <= r) {
                if (s[l + 1] == s[r]) {
                    dp[l][r] = add(dp[l][r], dp[l + 1][r]);
                }
            }
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;
}