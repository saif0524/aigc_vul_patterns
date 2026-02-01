#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    vector<pll> points(n);
    for (auto& point : points) {
        cin >> point.first >> point.second;
    }

    vector<set<ll>> bad(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (points[i].first * points[j].first + points[i].second * points[j].second == 0) {
                bad[i].insert(j);
                bad[j].insert(i);
            }
        }
    }

    vector<ll> dp(n);
    for (ll i = 0; i < n; i++) {
        set<ll> banned;
        for (auto& v : bad[i]) {
            banned.insert(v);
        }
        for (auto& v : bad[i]) {
            for (auto& u : bad[v]) {
                banned.insert(u);
            }
        }
        ll cnt = 1;
        for (ll j = 0; j < i; j++) {
            if (banned.find(j) == banned.end()) {
                cnt = (cnt + dp[j]) % MOD;
            }
        }
        dp[i] = cnt;
    }

    ll ans = 1;
    for (auto& c : dp) {
        ans = (ans + c) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }

    return 0;
}