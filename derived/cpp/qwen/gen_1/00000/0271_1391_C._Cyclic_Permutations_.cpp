#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll total_perms = power(2LL, n-1, MOD);
    ll acyclic = (n % 2 == 1) ? 1 : 2;
    for(ll k=3; k<=n; k+=2){
        ll cycles = power(n, k, MOD);
        for(ll j=1; j<=k-2; j++){
            cycles = (cycles * (n-1)) % MOD;
        }
        cycles = (cycles * power(k, MOD-2, MOD)) % MOD;
        cycles = (cycles * power(2, k-1, MOD)) % MOD;
        cyclic = (cyclic + cycles) % MOD;
    }
    ll result = (total_perms - acyclic + MOD) % MOD;
    cout << result;
    return 0;
}