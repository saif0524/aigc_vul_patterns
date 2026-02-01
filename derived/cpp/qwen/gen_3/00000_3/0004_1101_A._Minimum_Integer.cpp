#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        long long l, r, d;
        cin >> l >> r >> d;
        long long x = ((l-1)/d + 1) * d;
        if(x > r) cout << x << "\n";
        else cout << (r/d + 1) * d << "\n";
    }
}