#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &x : p) cin >> x;
    vector<ll> pref(n+1, 0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + abs(p[i] - (i+1));
    }
    ll total = pref[n];
    ll ans = total;
    int id = 0;
    for(int k=1;k<n;k++){
        ll dev = total - (pref[n] - pref[k]) + (pref[k] - pref[0] - (n-k));
        if(dev < ans){
            ans = dev;
            id = k;
        }
    }
    cout << ans << " " << id << "\n";
}