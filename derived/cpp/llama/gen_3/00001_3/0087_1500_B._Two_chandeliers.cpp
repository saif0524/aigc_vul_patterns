#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    ll lcm = n * m / gcd(n, m);

    vector<ll> diff(lcm, 0);
    for (ll i = 0; i < lcm; ++i) {
        if (a[i % n]!= b[i % m]) diff[i] = 1;
    }

    ll cnt = accumulate(diff.begin(), diff.end(), 0LL);
    ll ans = (k - 1) / cnt * lcm;

    for (ll i = 0; i < lcm; ++i) {
        if (a[i % n]!= b[i % m]) --k;
        if (k == 0) {
            ans += i + 1;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}