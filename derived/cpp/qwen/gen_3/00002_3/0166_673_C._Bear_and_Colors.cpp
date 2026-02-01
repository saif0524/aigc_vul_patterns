#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int &x : t) cin >> x;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; ++i){
        vector<int> cnt(n+1, 0);
        int mx = 0;
        for(int j = i; j < n; ++j){
            ++cnt[t[j]];
            mx = max(mx, cnt[t[j]]);
            if(cnt[t[j]] == mx) ans[t[j]-1] += (j-i+1) - (mx - cnt[t[j]]);
        }
    }
    for(int i = 0; i < n; ++i) cout << ans[i] << (i == n-1 ? '\n' : ' ');
}