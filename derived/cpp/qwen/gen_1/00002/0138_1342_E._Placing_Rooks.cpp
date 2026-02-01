#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long powmod(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

long long inv(long long x) {
    return powmod(x, MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    if(k < n-1 || k > n*(n-1)/2){
        cout << 0;
        return 0;
    }
    long long ans = powmod(n, n);
    for(long long i = 1; i <= n; i++)
        ans = (ans * inv(i)) % MOD;
    long long ways = 1;
    for(long long i = n-1; i > n-1-k; i--)
        ways = (ways * i) % MOD;
    for(long long i = 0; i < k-(n-1); i++)
        ways = (ways * (n-1-i)) % MOD;
    ans = (ans * ways) % MOD;
    ans = (ans * inv(powmod(2, k-(n-1)))) % MOD;
    cout << ans;
}