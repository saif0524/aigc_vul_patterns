#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (2 * c < a + b) {
        ll k = min(x, y);
        x -= k;
        y -= k;
        ll ans = k * 2 * c;
        ans += x * a;
        ans += y * b;
        cout << ans << endl;
    } else {
        cout << x * a + y * b << endl;
    }

    return 0;
}