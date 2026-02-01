#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(m);
    for(auto &x: p) cin >> x;
    ll ans = 0;
    ll last = 0;
    for(auto &x: p){
        ll page_x = (x-1)/k;
        ll page_last = (last-1)/k;
        if(page_x != page_last) ans++;
        last = x;
    }
    cout << ans << "\n";
}