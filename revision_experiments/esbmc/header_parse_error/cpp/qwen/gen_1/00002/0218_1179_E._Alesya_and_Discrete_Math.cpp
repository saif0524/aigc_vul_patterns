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

ll n, L, step, min_val[1005], max_val[1005];

ll ask(ll func, ll x) {
    cout << "? " << func + 1 << " " << x << endl;
    fflush(stdout);
    ll val;
    cin >> val;
    return val;
}

pair<ll, ll> find_segment(ll func) {
    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (ask(func, mid) == min_val[func]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ll start = l;
    l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (ask(func, mid) < max_val[func]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ll end = l;
    return {start, end};
}

int main(){
    cin >> n >> L;
    step = L / n;
    for (ll i = 0; i < n; i++) {
        min_val[i] = ask(i, 0);
        max_val[i] = ask(i, 1e18);
    }
    vector<pair<ll, ll>> segments;
    for (ll i = 0; i < n; i++) {
        segments.push_back(find_segment(i));
    }
    cout << "!" << endl;
    for (auto [l, r] : segments) {
        cout << l << " " << r << endl;
    }
    return 0;
}