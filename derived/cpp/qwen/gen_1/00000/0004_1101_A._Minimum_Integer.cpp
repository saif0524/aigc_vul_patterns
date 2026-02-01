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
        if(d > r){
            cout << d << "\n";
        }
        else{
            long long x = ((l + d - 1) / d) * d;
            if(x <= r){
                x += d;
            }
            cout << x << "\n";
        }
    }
}