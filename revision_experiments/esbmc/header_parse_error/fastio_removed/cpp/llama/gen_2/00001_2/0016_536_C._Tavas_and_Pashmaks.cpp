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
    ((void)0);
    ((void)0);
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