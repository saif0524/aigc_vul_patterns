// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>

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
    ((void)0);
    ((void)0);

    ll t = 1;
    // cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }

    return 0;
}