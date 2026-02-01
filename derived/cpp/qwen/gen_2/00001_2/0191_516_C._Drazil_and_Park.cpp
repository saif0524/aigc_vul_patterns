#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    for(auto &x: d) cin >> x;
    vector<ll> h(n);
    for(auto &x: h) cin >> x;
    vector<ll> pref(n+1, 0);
    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + d[i-1];
    vector<ll> hmax(n), hmaxrev(n);
    hmax[0] = h[0];
    for(int i=1;i<n;i++) hmax[i] = max(hmax[i-1], h[i]);
    hmaxrev[n-1] = h[n-1];
    for(int i=n-2;i>=0;i--) hmaxrev[i] = max(hmaxrev[i+1], h[i]);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        ll d1 = pref[b+1] - pref[a];
        ll d2 = pref[n] - pref[b+1] + pref[a];
        ll dval = max(d1, d2);
        ll hval1 = a > 0 ? hmax[a-1] : 0;
        ll hval2 = hmaxrev[b+1];
        ll hval = max(hval1, hval2);
        cout << 2*hval + dval << "\n";
    }
}