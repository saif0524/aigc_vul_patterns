#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, q;
        cin >> a >> b >> q;

        while (q--) {
            ll l, r;
            cin >> l >> r;
            ll ans = 0;

            for (ll x = l; x <= r; x++) {
                ll mod_a = x % a;
                ll mod_b = x % b;
                ll mod_ab = mod_a % b;
                ll mod_ba = mod_b % a;

                if (mod_ab != mod_ba) {
                    ans++;
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}