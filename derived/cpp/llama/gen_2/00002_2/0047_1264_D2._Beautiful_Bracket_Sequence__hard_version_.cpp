#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 998244353;

long long powmod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> fac(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    vector<long long> inv(n + 1);
    inv[n] = powmod(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
    auto C = [&](int n, int m) {
        if (n < m || m < 0) return 0LL;
        return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    };

    long long ans = 0;
    for (int d = 1; d <= n; d++) {
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '?') {
                long long ways = C(i, d - 1) * C(n - i - 1, d - 1) % MOD;
                cur = (cur + ways) % MOD;
            }
        }
        ans = (ans + cur) % MOD;
    }
    cout << ans << endl;
    return 0;
}