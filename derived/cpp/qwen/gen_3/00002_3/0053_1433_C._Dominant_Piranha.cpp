#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        int ans = -1;
        for(int i=0;i<n;i++){
            if((i==0 && a[i] > a[i+1]) || (i==n-1 && a[i] > a[i-1]) || (i>0 && i<n-1 && a[i] > a[i-1] && a[i] > a[i+1])){
                ans = i+1;
                break;
            }
        }
        cout << ans << "\n";
    }
}