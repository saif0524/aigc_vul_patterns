#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000000+ 7;

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n == 3){
        cout << 2;
        return 0;
    }
    ll fact = 1;
    for(int i = 1; i <= n; ++i){
        fact = (fact * i) % MOD;
    }
    ll inv_fact = mod_exp(fact, MOD - 2, MOD);
    ll ans = (fact * inv_fact) % MOD;
    ans = (ans * (n - 1)) % MOD;
    ans = (ans * (n - 2)) % MOD;
    cout << ans;
    return 0;
}