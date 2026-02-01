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
        long long left = -1e18, right = 1e18;
        for(int i=0;i<n;i++){
            long long l, r;
            cin >> l >> r;
            left = max(left, l);
            right = min(right, r);
        }
        if(left <= right){
            cout << (right - left) << "\n";
        }
        else{
            cout << "0\n";
        }
    }
}