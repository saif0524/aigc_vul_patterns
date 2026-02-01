#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> c(n*k), f(n), h(k);
    for(auto &x: c) cin >> x;
    for(auto &x: f) cin >> x;
    for(auto &x: h) cin >> x;
    
    sort(c.rbegin(), c.rend());
    map<int, int> freq;
    for(auto x: c) freq[x]++;
    
    vector<int> tar(n, k);
    for(auto &x: tar) cin >> x;
    int ans = 0;
    
    for(int i=0;i<n;i++){
        int need = tar[i];
        int joy = 0;
        for(int j=k-1;j>=0;j--){
            int cnt = min(freq[f[i]], need);
            freq[f[i]] -= cnt;
            joy += cnt * h[j];
            need -= cnt;
        }
        ans += joy;
    }
    
    cout << ans;
}