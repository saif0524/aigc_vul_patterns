#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    
    ll x = -1, y = -1, z = -1;
    bool found = false;
    
    for(ll k = 0; k <= n && !found; ++k){
        if((p - d*k) % (w - d) == 0){
            ll x = (p - d*k) / (w - d);
            ll y = k;
            ll z = n - x - y;
            if(x >= 0 && y >= 0 && z >= 0){
                found = true;
            }
        }
    }
    
    if(found){
        cout << x << " " << y << " " << z;
    }
    else{
        cout << -1;
    }
    
    return 0;
}