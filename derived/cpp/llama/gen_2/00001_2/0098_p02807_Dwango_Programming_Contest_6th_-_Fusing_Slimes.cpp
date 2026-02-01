#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

long long powmod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return powmod(a, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector<long long> fac(n);
    fac[0] = 1;
    for (int i = 1; i < n; ++i) fac[i] = fac[i - 1] * i % mod;
    vector<int> cnt(n - 1);
    for (int i = 0; i < n - 1; ++i) cnt[i] = x[i + 1] - x[i];
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long tot = 0;
        for (int j = 0; j < i + 1; ++j) tot = (tot + fac[i] * inv(fac[j]) % mod * inv(fac[i - j]) % mod * (i - j)) % mod;
        ans = (ans + cnt[i] * tot) % mod;
    }
    cout << ans << endl;
    return 0;
}