#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        cin >> n >> m >> k;
        long long d = abs(n) + abs(m);
        if(d > k || (k - d)&1){
            cout << -1 << "\n";
        }
        else{
            cout << min(d, k - d/2) << "\n";
        }
    }
}