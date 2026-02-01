#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    if (p % d == 0 && p / d <= n) {
        cout << 0 << " " << p / d << " " << n - (p / d);
        return 0;
    }

    ll k = (w - p % d) % d;
    ll mod = d;
    ll y = -1;
    ll x = -1;
    ll z;

    for (ll i = 0; i <= n; ++i) {
        ll current_y = (k - i * w) % mod;
        if (current_y < 0) current_y += mod;
        if ((p - i * w - current_y * d) % w == 0) {
            y = current_y;
            x = (p - i * w - current_y * d) / w;
            break;
        }
    }

    if (x >= 0 && y >= 0 && x + y <= n) {
        z = n - x - y;
        cout << x << " " << y << " " << z;
    } else {
        cout << -1;
    }
}