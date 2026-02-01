#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<long long> pref(n+1);
    for(int i=0; i<n; i++) pref[i+1] = pref[i] + a[i];
    long long ans = LLONG_MAX;
    for(int i=0; i<=n-k; i++){
        long long cnt = 1LL * a[i+k-1] * k - (pref[i+k] - pref[i]);
        cnt += (pref[n] - pref[i+k]) - 1LL * a[i+k-1] * (n-k);
        ans = min(ans, cnt);
    }
    cout << ans;
}