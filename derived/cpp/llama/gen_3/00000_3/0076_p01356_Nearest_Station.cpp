#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main() {
    ll n, m, a, b, p, q;
    std::cin >> n >> m >> a >> b >> p >> q;

    std::vector<ll> dist;

    for (ll i = 0; i < n; ++i) {
        ll temp = (p * (a * i) + q * (b * i));
        dist.push_back(temp);
    }

    std::sort(dist.begin(), dist.end());

    ll ans = 1e17;
    ll val = 0;

    for (ll i = 0; i < n; ++i) {
        if (dist[i] < m) {
            ll diff = m - dist[i];
            ans = std::min(ans, diff);
        } else {
            ll diff = dist[i] - m;
            ans = std::min(ans, diff);
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}