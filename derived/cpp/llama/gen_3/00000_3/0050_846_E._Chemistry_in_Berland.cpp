#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 1e12;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> b(n), a(n);
    for (ll i = 0; i < n; i++) cin >> b[i];
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<pair<ll, ll>> transformations(n - 1);
    for (ll i = 0; i < n - 1; i++) {
        cin >> transformations[i].first >> transformations[i].second;
        transformations[i].first--;
    }

    for (ll i = n - 2; i >= 0; i--) {
        ll x = transformations[i].first;
        ll k = transformations[i].second;

        ll g = gcd(k, a[i + 1]);
        ll take = min(b[x], a[i + 1] / g * k);
        b[x] -= take;
        b[i + 1] += take / k;
    }

    for (ll i = 0; i < n; i++) {
        if (b[i] < a[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}