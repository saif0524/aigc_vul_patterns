#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    
    ll x = -1, y = -1, z = -1;
    bool found = false;
    
    if (w > p || d > p) {
        cout << "-1";
        return 0;
    }
    
    for (ll y = 0; y <= n && !found; ++y) {
        if ((p - y * d) % w == 0) {
            x = (p - y * d) / w;
            if (x + y <= n) {
                z = n - x - y;
                found = true;
            }
        }
    }
    
    if (found) {
        cout << x << " " << y << " " << z;
    } else {
        cout << "-1";
    }
    
    return 0;
}