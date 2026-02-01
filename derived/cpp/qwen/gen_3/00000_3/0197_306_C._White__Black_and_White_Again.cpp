#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000009;

ll power_mod(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll comb_mod(ll n, ll k, vector<ll>& fact, vector<ll>& inv_fact) {
    if (k > n) return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, w, b;
    cin >> n >> w >> b;
    
    vector<ll> fact(n + w + b + 1, 1);
    vector<ll> inv_fact(n + w + b + 1, 1);
    
    for(ll i = 2; i <= n + w + b; ++i){
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = power_mod(fact[i], MOD - 2, MOD);
    }
    
    ll ans = 0;
    for(ll i = 1; i <= min(w, n - 2); ++i){
        for(ll j = 1; j <= min(b, n - i - 1); ++j){
            ll temp = comb_mod(n - 2, i - 1, fact, inv_fact);
            temp = (temp * comb_mod(n - i - 1, j - 1, fact, inv_fact)) % MOD;
            temp = (temp * fact[i]) % MOD;
            temp = (temp * fact[j]) % MOD;
            temp = (temp * fact[w - i]) % MOD;
            temp = (temp * fact[b - j]) % MOD;
            ans = (ans + temp) % MOD;
        }
    }
    
    cout << ans;
    return 0;
}