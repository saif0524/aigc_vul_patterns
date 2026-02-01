#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, q;
    cin >> n >> k >> q;
    ll fact[n+1], ifact[n+1];
    fact[0] = ifact[0] = 1;
    for(ll i=1;i<=n;i++){
        fact[i] = (fact[i-1]*i)%q;
    }
    ifact[n] = modPow(fact[n], q-2, q);
    for(ll i=n-1;i>=1;i--){
        ifact[i] = (ifact[i+1]*(i+1))%q;
    }
    ll ways[n+1];
    ways[0] = 1;
    for(ll i=1;i<=n;i++){
        ways[i] = 0;
        for(ll j=1;j<=k && i >= (1<<(j-1));j++){
            ways[i] = (ways[i] + (ways[i-(1<<(j-1))] * ifact[i-(1<<(j-1))]) % q * ifact[(1<<(j-1))]) % q;
        }
        ways[i] = (ways[i] * fact[i]) % q;
    }
    ll total = fact[n];
    ll inversions = 0;
    for(ll i=1;i<=n;i++){
        inversions = (inversions + (ways[i] * (fact[i-1] * fact[n-i]) % q) % q * (i * (n-i+1)) % q) % q;
    }
    ll inv_total = modPow(total, q-2, q);
    ll result = (inversions * inv_total) % q;
    cout << result;
}