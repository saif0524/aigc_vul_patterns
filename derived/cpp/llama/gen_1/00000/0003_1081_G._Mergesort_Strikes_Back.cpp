#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long long fac[100005];
long long facinv[100005];

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

long long dp[100005];

long long f(int n, int k, int mod) {
    if (n <= 1) return 0;
    if (k == 1) return (long long)n * (n - 1) / 2;
    if (dp[n] != -1) return dp[n];
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += f(i - 1, k - 1, mod) * facinv[i - 1] % mod * facinv[n - i] % mod;
        res += f(n - i, k - 1, mod) * facinv[i - 1] % mod * facinv[n - i] % mod;
        res %= mod;
    }
    res += (long long)n * (n - 1) / 2 * (k - 1 == 1);
    res %= mod;
    dp[n] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % q;
    facinv[n] = modinv(fac[n], q);
    for (int i = n - 1; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1) % q;
    fill(dp, dp + 100005, -1);
    cout << (f(n, min(k, n), q) * modinv((n * (n - 1) / 2) % q, q) % q + q) % q << endl;
    return 0;
}