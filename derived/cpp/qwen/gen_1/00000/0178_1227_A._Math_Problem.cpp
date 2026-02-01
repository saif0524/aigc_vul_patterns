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
        long long l=1, r=1e9, min_r=1e9, max_l=1, ans=0;
        for(int i=0;i<n;i++){
            long long a, b;
            cin >> a >> b;
            min_r = min(min_r, b);
            max_l = max(max_l, a);
        }
        ans = max(0LL, max_l - min_r);
        cout << ans << "\n";
    }
}