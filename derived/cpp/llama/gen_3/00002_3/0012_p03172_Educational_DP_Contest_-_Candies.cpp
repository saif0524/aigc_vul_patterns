#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

int inv(int a) {
    return binpow(a, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= min(j, a[i - 1]); ++l) {
                dp[i][j] = add(dp[i][j], dp[i - 1][j - l]);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}