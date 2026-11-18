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
using ll = long long;
const ll MOD = 998244353;

map<ll, ll> prime_count;
map<ll, ll> mask_to_count;

void update_mask_to_count(ll mask, ll count) {
    if (mask_to_count.find(mask) == mask_to_count.end()) {
        mask_to_count[mask] = count;
    } else {
        mask_to_count[mask] = max(mask_to_count[mask], count);
    }
}

void add_prime(ll prime) {
    prime_count[prime]++;
}

ll pow_mod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a, ll mod) {
    return pow_mod(a, mod - 2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll p;
        cin >> p;
        add_prime(p);
    }

    ll m = prime_count.size();

    vector<ll> primes;
    vector<ll> counts;

    for (const auto& pair : prime_count) {
        primes.push_back(pair.first);
        counts.push_back(pair.second);
    }

    mask_to_count[0] = 1;

    for (ll i = 0; i < m; i++) {
        ll prime = primes[i];
        ll count = counts[i];

        vector<ll> new_masks;
        for (const auto& [mask, curr_count] : mask_to_count) {
            update_mask_to_count(mask | (1LL << i), (curr_count * (count + 1)) % MOD);
            for (ll r = 1; r <= count; r++) {
                new_masks.push_back(mask | (r << i));
            }
        }

        for (ll new_mask : new_masks) {
            ll new_count = 1;
            for (ll j = 0; j < m; j++) {
                ll bits = (new_mask >> j) & 0x7FFFFFFF;
                if (bits == 0) continue;
                new_count = (new_count * (bits + 1)) % MOD;
            }
            update_mask_to_count(new_mask, new_count);
        }
    }

    ll ans = 0;

    for (const auto& [mask, count] : mask_to_count) {
        vector<ll> ks;
        for (ll i = 0; i < m; i++) {
            ll bits = (mask >> i) & 0x7FFFFFFF;
            if (bits == 1) ks.push_back(i);
        }

        ll prod = 1;
        for (ll k : ks) {
            prod = (prod * (counts[k] + 1)) % MOD;
        }

        if (ks.size() % 2 == 0) {
            ans = (ans + count) % MOD;
        } else {
            ans = (ans + MOD - count) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}