#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll ans = 0;
    
    if(a < b){
        ans = n / a;
    } else {
        ll m = n / b;
        ans += m;
        ll re = m * c;
        while(re + n >= b){
            ll add = (re + n) / b;
            ans += add;
            re = add * c;
            n = (re + n) % b;
        }
    }
    
    cout << ans;
}