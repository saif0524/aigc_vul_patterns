#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    long long ans = LLONG_MAX;
    for(int i = 0; i <= k; ++i){
        long long cur = 0;
        for(int j = 0; j < n - k - 1; ++j){
            if(j < i) cur += abs(a[j] - a[j+1]);
            else cur += abs(a[j] - a[j+k+1]);
        }
        ans = min(ans, cur);
    }
    cout << ans;
}