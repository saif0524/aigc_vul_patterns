#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll n, m, a, b, p, q;
    cin >> n >> m >> a >> b >> p >> q;

    ll min_steps = LLONG_MAX;
    for(ll i = 0; i < n; ++i){
        ll dest = p * (a * i) + q * (b * i);
        if(dest <= m){
            min_steps = min(min_steps, m - dest);
        }
    }

    ll count = 0;
    for(ll i = 0; i < n; ++i){
        ll dest = p * (a * i) + q * (b * i);
        if(dest + min_steps == m){
            ++count;
        }
    }

    cout << count;
}