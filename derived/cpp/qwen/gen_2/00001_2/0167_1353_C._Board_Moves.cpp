#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n == 1){
            cout << 0 << "\n";
        }
        else{
            long long mid = n/2;
            long long ans = mid * (mid + 1) * (4 * mid + 2);
            cout << ans << "\n";
        }
    }
}