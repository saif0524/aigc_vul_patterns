#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        ll mid = n/2;
        ll total_moves = (mid * (mid+1) * (2*mid+1)/6) * 8;
        cout << total_moves << "\n";
    }
    return 0;
}