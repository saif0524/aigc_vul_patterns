#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> x(N);
    for(auto &xi: x) cin >> xi;
    ll ans = 0;
    for(int i=0; i<N-1; ++i){
        ans = (ans + (x[i+1] - x[i]) * (ll(i + 1)) * (ll(N - i - 1)) % MOD) % MOD;
    }
    ans = (ans * mod_exp(mod_exp(2, MOD-2), N-1)) % MOD;
    cout << ans;
}