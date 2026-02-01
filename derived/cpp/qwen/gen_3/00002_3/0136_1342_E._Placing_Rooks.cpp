#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long comb(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) % MOD;
        res = res * modinv(i + 1) % MOD;
    }
    return res;
}

long long modinv(long long a) {
    long long b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for(int i=0; i<=k; ++i){
        long long c1 = comb(n, i);
        long long c2 = comb(n-i, k-i);
        long long c3 = modinv(n-i);
        long long term = c1 * c2 % MOD * c3 % MOD;
        if((k-i)&1) ans = (ans - term + MOD) % MOD;
        else ans = (ans + term) % MOD;
    }
    ans = ans * factorial(n) % MOD * factorial(n) % MOD;
    cout << ans;
}

long long factorial(int n){
    long long res = 1;
    for(int i=2; i<=n; ++i){
        res = res * i % MOD;
    }
    return res;
}