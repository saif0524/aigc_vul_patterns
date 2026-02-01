#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr(n);
    for(auto &x: arr) cin >> x;
    
    auto g = [&](long long x, long long y){
        while(y){
            long long t = y;
            y = x % y;
            x = t;
        }
        return x;
    };
    
    long long ans = LLONG_MAX;
    
    // Case: Removing a subsegment
    vector<long long> pref(n+1);
    for(long long i=1; i<=n; i++) pref[i] = g(pref[i-1], arr[i-1]);
    
    for(long long i=1; i<n; i++){
        long long current = a * i;
        long long suf = arr[i];
        for(long long j=i+1; j<n; j++) suf = g(suf, arr[j]);
        if(pref[i] > 1 || suf > 1) ans = min(ans, current);
    }
    
    // Case: Changing elements
    for(long long x=2; x<=1000; x++){
        long long current = 0;
        for(auto &y: arr){
            if(y % x != 0) current += b * min(y % x, x - y % x);
        }
        if(current < ans) ans = current;
    }
    
    cout << ans;
}