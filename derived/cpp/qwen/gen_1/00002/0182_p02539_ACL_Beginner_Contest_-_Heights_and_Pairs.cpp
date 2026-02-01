#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> h(2*N);
    for(auto &x: h) cin >> x;
    sort(h.begin(), h.end());
    ll fact[100005] = {1};
    for(int i=1;i<=2*N;i++) fact[i] = fact[i-1] * i % MOD;
    ll inv_fact[100005] = {1, 1};
    for(int i=2;i<=2*N;i++) inv_fact[i] = MOD - MOD/i * inv_fact[MOD%i] % MOD;
    for(int i=2;i<=2*N;i++) inv_fact[i] = inv_fact[i] * inv_fact[i-1] % MOD;
    ll ans = fact[2*N];
    for(int i=0;i<2*N-1;i+=2){
        if(h[i] == h[i+1]){
            cout << 0;
            return 0;
        }
        ans = ans * inv_fact[2] % MOD;
    }
    cout << ans;
}