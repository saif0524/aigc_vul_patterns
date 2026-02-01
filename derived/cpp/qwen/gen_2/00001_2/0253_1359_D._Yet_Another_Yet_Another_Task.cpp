#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    
    vector<int> pref(n+1);
    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + a[i-1];
    
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int total = pref[j+1] - pref[i];
            int max_val = INT_MIN;
            for(int k=i;k<=j;k++){
                max_val = max(max_val, a[k]);
            }
            ans = max(ans, total - max_val);
        }
    }
    
    cout << ans;
}