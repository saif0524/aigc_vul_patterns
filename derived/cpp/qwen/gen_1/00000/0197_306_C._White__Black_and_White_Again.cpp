#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;

long long fact[4001], inv_fact[4001];

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

long long comb(int n, int k) {
    if (k > n) return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w, b;
    cin >> n >> w >> b;
    precompute(n + b + w);
    long long ans = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= b; j++) {
            if (i + j + 1 == n) {
                long long ways = comb(w, i);
                long long ways2 = comb(b, j);
                ans = (ans + (ways * ways2) % MOD) % MOD;
            }
        }
    }
    cout << ans;
}