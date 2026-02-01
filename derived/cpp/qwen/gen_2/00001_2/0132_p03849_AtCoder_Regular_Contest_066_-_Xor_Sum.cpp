#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fastpow(ll b, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i=0; (1LL<<i) - 1 <= N; ++i){
        ll block = (1LL<<(i+1)) - 1;
        ll complete = N / block;
        ll rem = N % block;
        if(rem < (1LL<<i)){
            ans = (ans + (complete % MOD) * fastpow(3LL, i) % MOD) % MOD;
        }else{
            ans = (ans + ((complete + 1) % MOD) * fastpow(3LL, i) % MOD) % MOD;
        }
    }
    cout << ans;
}