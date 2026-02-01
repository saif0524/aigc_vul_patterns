#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> x(N);
    for(auto &a : x) cin >> a;
    vector<ll> fact(N+1, 1);
    for(int i=1;i<=N;i++) fact[i] = (fact[i-1] * i) % MOD;
    ll ans = 0;
    for(int i=0;i<N-1;i++){
        ll d = x[i+1] - x[i];
        ans = (ans + d * (fact[N-1-i] * (i+1) % MOD)) % MOD;
    }
    cout << ans;
}