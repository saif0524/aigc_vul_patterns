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

const ll MAX = 1e12;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ((void)0);
    ((void)0);

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