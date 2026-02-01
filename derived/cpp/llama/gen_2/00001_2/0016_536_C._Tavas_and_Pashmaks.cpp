#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll n;
pll p[MAXN];
bool can[MAXN];

bool check(ll i, ll j) {
    for (ll k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (p[k].first * p[i].second > p[i].first * p[k].second && p[k].first * p[j].second > p[j].first * p[k].second) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        for (ll j = 0; j < n; j++) {
            if (i == j) continue;
            if (p[i].first * p[j].second > p[j].first * p[i].second) can[i] = true;
        }
    }

    for (ll i = 0; i < n; i++) {
        if (!can[i]) continue;
        bool ok = true;
        for (ll j = 0; j < n; j++) {
            if (i == j) continue;
            if (can[j] && !check(i, j)) ok = false;
        }
        if (ok) cout << i + 1 << ' ';
    }

    return 0;
}