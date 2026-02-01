#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

int mul(int a, int b) {
    return (long long)a * b % mod;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (k > n * n) {
        cout << powmod(2, n) << endl;
        return 0;
    }
    vector<int> dp(1 << n, 0);
    for (int i = 0; i < (1 << n); i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                if (((i >> j) & 1) && ((i >> l) & 1)) ok = false;
            }
        }
        if (ok) dp[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        vector<int> ndp(1 << (i * n), 0);
        for (int j = 0; j < (1 << (i * n)); j++) {
            int up = j >> n;
            int down = j & ((1 << n) - 1);
            bool ok = true;
            for (int l = 0; l < n; l++) {
                if (((up >> l) & 1) && ((down >> l) & 1)) ok = false;
            }
            if (!ok) continue;
            int cnt = dp[up];
            if (i > 1) cnt = mul(cnt, dp[down]);
            ndp[j] = cnt;
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = 0; i < (1 << (n * n)); i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                for (int x = j + 1; x < n; x++) {
                    for (int y = l + 1; y < n; y++) {
                        int cnt = 0;
                        for (int p = j; p <= x; p++) {
                            for (int q = l; q <= y; q++) {
                                if (((i >> (p * n + q)) & 1) == 1) cnt++;
                            }
                        }
                        if (cnt >= k) ok = false;
                    }
                }
            }
        }
        if (ok) ans = add(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}