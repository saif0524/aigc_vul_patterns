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

const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ll lcm_val = b[0];
    for (int i = 1; i < n; i++) {
        lcm_val = lcm(lcm_val, b[i]);
    }

    ll ans = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (lcm_val == b[i]) {
                ans = 1;
                break;
            }
            continue;
        }
        ll val = lcm_val / b[i];
        if (val == 0) {
            continue;
        }
        ll temp = a[i];
        while (temp % a[i]) {
            temp *= b[i];
            if (temp > 1e18) break;
        }
        if (temp % a[i] == 0 && temp % lcm_val == 0) {
            if (ans == -1) {
                ans = temp;
            } else {
                ans = gcd(ans, temp);
            }
        } else {
            ans = -1;
            break;
        }
    }

    if (ans == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans % mod << '\n';
    }
}