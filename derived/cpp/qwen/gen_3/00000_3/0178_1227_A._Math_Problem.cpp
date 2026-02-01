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
        long long l=0, r=1e9+1;
        for(int i=0;i<n;i++){
            long long ll, rr;
            cin >> ll >> rr;
            l = max(l, ll);
            r = min(r, rr);
        }
        if(l > r){
            cout << r-l+1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }
}