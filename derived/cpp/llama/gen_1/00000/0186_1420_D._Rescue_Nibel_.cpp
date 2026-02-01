#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll mod) {
    return powmod(a, mod - 2, mod);
}

ll nCk(ll n, ll k, ll mod) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;

    if (k == 0) return 1;

    ll result = 1;
    for (ll i = 0; i < k; ++i) {
        result = result * (n - i) % mod;
        result = result * inv(i + 1, mod) % mod;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, pii>> events;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, {i, 1}});
        events.push_back({r + 1, {i, -1}});
    }

    sort(events.begin(), events.end());

    vector<ll> ans;
    vector<int> lampsOn(n, 0);
    int curLamps = 0;

    for (int i = 0; i < events.size(); i++) {
        pair<int, pii> &e = events[i];

        if (e.second.second == 1) {
            lampsOn[e.second.first]++;
            curLamps++;
        }
        else {
            lampsOn[e.second.first]--;
            curLamps--;
        }

        if (curLamps == k && i + 1 < events.size()) {
            ans.push_back(nCk(curLamps, k, mod));
        }
    }

    ll total = 0;
    for (auto j : ans) {
        total = (total + j) % mod;
    }

    cout << total % mod;
    return 0;
}