#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<ll> ps(n+1, 0);
    for(int i=0;i<n;i++) ps[i+1] = ps[i] + a[i];
    ll ans = LLONG_MAX;
    for(int i=0;i+k<=n;i++){
        ll need = 1LL * (k) * 1LL * a[i+k-1] - (ps[i+k] - ps[i]);
        ans = min(ans, need);
    }
    for(int i=k-1;i<n;i++){
        ll need = (ps[i+1] - ps[i-k+1]) - 1LL * (k) * 1LL * a[i-k+1];
        ans = min(ans, need);
    }
    cout << ans;
}