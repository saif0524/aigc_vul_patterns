#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, q;
    std::cin >> n >> q;

    std::vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::set<ll> s;
    while (q--) {
        ll x;
        std::cin >> x;

        if (s.find(x) != s.end()) {
            s.erase(x);
        } else {
            s.insert(x);
        }

        ll ans = 0;
        std::vector<ll> v(s.begin(), s.end());
        for (ll i = 0; i < v.size(); ++i) {
            for (ll j = i + 1; j < v.size(); ++j) {
                if (gcd(a[v[i]], a[v[j]]) > 1) {
                    ++ans;
                }
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}