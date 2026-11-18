#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    ll D;
    cin >> N >> M >> K >> D;
    vector<ll> fact(N+M, 1);
    for(int i=2;i<N+M;i++){
        fact[i] = fact[i-1] * i % D;
    }
    vector<ll> invfact(N+M, 1);
    invfact[N+M-1] = modpow(fact[N+M-1], D-2, D);
    for(int i=N+M-2;i>=1;i--){
        invfact[i] = invfact[i+1] * (i+1) % D;
    }
    auto comb = [&](int n, int k){
        if(k < 0 || k > n) return 0LL;
        return fact[n] * invfact[k] % D * invfact[n-k] % D;
    };
    ll ans = 0;
    for(int r=1;r<=K;r++){
        for(int c=1;c<=K;c++){
            ll prod = 1;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    int mn = min(r+i-1, c+j-1);
                    prod = prod * mn % D;
                }
            }
            ll ways = comb(N+M-2, N-1);
            ways = ways * modpow(K-1, N*M-(N+M-1), D) % D;
            ans = (ans + prod * ways % D) % D;
        }
    }
    cout << ans << "\n";
    return 0;
}