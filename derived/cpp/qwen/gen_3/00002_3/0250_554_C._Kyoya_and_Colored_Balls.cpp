#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<int> c(k);
    ll total = 0;
    for(int &x : c){
        cin >> x;
        total += x;
    }
    vector<ll> fact(total + 1, 1);
    for(int i=2;i<=total;i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    ll den = 1;
    for(int x : c){
        den = (den * fact[x]) % MOD;
    }
    ll ans = (fact[total] * modInverse(den, MOD)) % MOD;
    cout << ans;
}