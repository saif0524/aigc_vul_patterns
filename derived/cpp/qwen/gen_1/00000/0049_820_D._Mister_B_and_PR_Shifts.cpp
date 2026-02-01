#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &x: p) cin >> x;
    vector<ll> pref(n+1, 0);
    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + p[i-1] - i;
    vector<ll> suf(n+1, 0);
    for(int i=n-1; i>=0; i--) suf[i] = suf[i+1] + p[i] - (i+1);
    ll min_dev = 1e18;
    int best_id = 0;
    for(int k=0; k<n; k++){
        ll dev = suf[(k+1)%n] - suf[0] + pref[n] - pref[(k+1)%n];
        if(dev < min_dev){
            min_dev = dev;
            best_id = k;
        }
    }
    cout << min_dev << " " << best_id;
}