#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

long long fac[MAXN];
long long ifac[MAXN];

long long powmod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return (fac[n] * ifac[m] % MOD * ifac[n - m]) % MOD;
}

long long binom() {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        ifac[i] = powmod(fac[i], MOD - 2);
    }
}

int main() {
    int n;
    cin >> n;

    binom();

    long long ans = fac[n] % MOD;

    for (int i = 1; i < n; i++) {
        ans -= ((fac[i - 1] * fac[n - i]) % MOD * fac[n - 1]) % MOD;
        ans = (ans + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}