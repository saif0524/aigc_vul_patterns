#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll modpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

bool subset(const set<ll>& small, const set<ll>& large) {
    for (ll x : small) {
        if (large.find(x) == large.end()) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<set<ll>> progs(n);
    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        set<ll> s;
        for (int j = 0; j < 40 && a <= MOD; j++){
            s.insert(a);
            a *= b;
        }
        progs[i] = s;
    }
    for (int i = 1; i < n; i++){
        set<ll> new_set;
        for (ll x : progs[0]){
            if (progs[i].find(x) != progs[i].end()){
                new_set.insert(x);
            }
        }
        if (new_set.empty()){
            cout << -1;
            return 0;
        }
        progs[0] = new_set;
    }
    ll ans = *progs[0].begin();
    cout << ans;
}