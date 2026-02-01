#include <iostream>
#include <vector>

typedef long long ll;

ll function(ll x) {
    ll ans = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            ans++;
        }
        x /= 2;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    std::cin >> n;

    std::vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            if (function(a[i]) == function(a[j])) {
                ans++;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}