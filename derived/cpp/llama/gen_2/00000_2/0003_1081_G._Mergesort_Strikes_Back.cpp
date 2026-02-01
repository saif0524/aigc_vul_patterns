#include <iostream>
using namespace std;

const int MAXN = 100002;

long long fac[MAXN], inv[MAXN], finv[MAXN];
long long q;

long long pow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % q;
        a = a * a % q;
        b >>= 1;
    }
    return res;
}

long long invs(long long a) {
    return pow(a, q - 2);
}

long long comb(long long n, long long m) {
    return fac[n] * finv[m] % q * finv[n - m] % q;
}

long long C(long long n, long long m) {
    if (n < 0 || m < 0 || m > n) return 0;
    return comb(n, m);
}

int main() {
    int n, k;
    cin >> n >> k >> q;
    fac[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (q - q / i) * inv[q % i] % q;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % q;
    finv[n] = invs(fac[n]);
    for (int i = n - 1; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1) % q;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long cnt = C(n - 1, i - 1);
            long long val = 0;
            if (i + (n - i) / (1 << (k - 1)) + 1 > j) {
                val = C(n - i, j - i - (n - i) / (1 << (k - 1)));
                val = val * (n - j + 1) % q;
                val = val * (n - i) % q;
                val = val * invs((n - i) / (1 << (k - 1)) + 1) % q;
            }
            ans = (ans + cnt * val % q) % q;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long cnt = C(n - 1, i - 1);
            long long val = 0;
            if (i + (n - i + 1) / (1 << (k - 1)) <= j) {
                val = C(n - i, j - i - (n - i) / (1 << (k - 1)) - 1);
                val = val * (n - j + 1) % q;
                val = val * (n - i) % q;
                val = val * invs((n - i) / (1 << (k - 1)) + 1) % q;
            }
            ans = (ans + cnt * val % q) % q;
        }
    }
    ans = ans * invs(2) % q * invs(fac[n]) % q;
    cout << ans << endl;
    return 0;
}