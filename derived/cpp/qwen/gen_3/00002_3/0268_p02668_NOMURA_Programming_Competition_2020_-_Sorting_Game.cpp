#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = modpow(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2) ? (p * x) % m : p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    ll ans = modpow(2, (N*M-M), MOD);
    cout << ans << endl;
    return 0;
}