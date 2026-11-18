#ifndef BZ
#pragma GCC optimize "-O3"
#endif
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

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

struct st {
    ll a, b;
};

const int N = 120000;

st a[N];

int n;
ll sm[N];

ll ap = 0;
ll aq = 1;

ll gcd(ll a, ll b) {
    while (b) {
        ll q = a % b;
        a = b;
        b = q;
    }
    return a;
}

using lll = __int128_t;

void upd(ll p, ll q) {
    ll g = gcd(p, q);
    p /= g, q /= g;
    if (lll(ap) * q < lll(p) * aq) {
        ap = p;
        aq = q;
    }
}

int main() {
	((void)0), ((void)0), ((void)0);
	cout.setf(ios::fixed), cout.precision(20);
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b;
        sum += a[i].a;
    }
    sort(a, a + n, [] (st a, st b) {
                return max(a.a, a.b) > max(b.a, b.b);
            });
    sm[0] = 0;
    for (int i = 0; i < n; ++i) {
        sm[i + 1] = sm[i] + max(a[i].a, a[i].b);
    }
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int r = n + 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            ll cur = sum - a[i].b - sm[m];
            if (i < m) {
                cur += max(a[i].a, a[i].b);
            }
            if (cur > 0) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r <= n) {
            int cnt = r;
            if (i >= r) {
                ++cnt;
            }
            cnt = n - cnt;
            ll cur = sum - sm[r];
            if (i < r) {
                cur += max(a[i].a, a[i].b);
            }
            if (cur <= 0) {
                upd(cnt + 1, n);
            } else {
                assert(cur <= a[i].b);
                ll p = cnt * a[i].b + a[i].b - cur;
                ll q = a[i].b * n;
                upd(p, q);
            }
        }
    }
    cout << ap << " " << aq << "\n";
	return 0;
}