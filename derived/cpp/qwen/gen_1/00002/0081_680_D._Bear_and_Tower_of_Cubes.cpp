#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll m;
    cin >> m;
    ll best_x = 0, best_blocks = 0;
    for(ll x=1;x*x*x<=m;x++){
        ll remaining = m;
        ll blocks = 0;
        for(ll i=x;i>=1;i--){
            ll cube = i*i*i;
            if(cube > remaining) continue;
            ll count = remaining / cube;
            blocks += count;
            remaining -= count * cube;
        }
        if(blocks > best_blocks || (blocks == best_blocks && x > best_x)){
            best_blocks = blocks;
            best_x = x*x*x;
        }
    }
    cout << best_blocks << " " << best_x << endl;
}