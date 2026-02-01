#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    
    long long sum = 0;
    for(auto x: a) sum += x;
    
    vector<long long> pref_min(n+1, 0), pref_max(n+1, 0);
    for(int i=0; i<n; ++i){
        pref_min[i+1] = min(pref_min[i], 1LL*a[i]);
        pref_max[i+1] = max(pref_max[i], 1LL*a[i]);
    }
    
    double ans = 1e18;
    for(int i=0; i<=n; ++i){
        long long mx = max(pref_max[i] - pref_min[n] + pref_min[i], pref_max[n] - pref_max[i] + pref_min[n] - pref_min[i]);
        ans = min(ans, (double)(sum - mx) / 2.0);
    }
    
    cout << fixed << setprecision(15) << ans;
    return 0;
}