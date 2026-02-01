#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(m);
    for(auto &x: p) cin >> x;
    
    ll operations = 0;
    for(ll i=0; i<m; ){
        ll page = (p[i] - 1) / k;
        ll count = 0;
        while(i < m && (p[i] - 1) / k == page){
            count++;
            i++;
        }
        operations++;
        if(count == k){
            page--;
        }
    }
    
    cout << operations;
}