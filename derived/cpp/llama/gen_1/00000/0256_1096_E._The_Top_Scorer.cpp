#include <iostream>
#include <algorithm>

const int mod = 998244353;

long long fac[5005], inv[5005], n, s, r;

long long qpow(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

long long C(int x, int y) {
    if (x < y) return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main() {
    std::cin >> n >> s >> r;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    long long ans = 0;
    for (int i = r; i <= s; i++) {
        long long q = 1;
        int t = i, now = s - i, cnt = n - 1;
        while (now >= t && cnt) {
            q = q * C(now + cnt - 1, cnt - 1) % mod;
            now -= t;
            cnt--;
        }
        if (cnt && now < t) q = 0;
        if (r == i) q = q * qpow(2, cnt) % mod;
        else q = q * qpow(2, cnt - 1) % mod;
        ans = (ans + q) % mod;
    }
    long long tmp = 0;
    for (int i = 0; i <= s; i++) {
        tmp = (tmp + C(i + n - 2, n - 2)) % mod;
    }
    tmp = qpow(tmp, mod - 2);
    std::cout << ans * tmp % mod << std::endl;
    return 0;
}