//
// Created by Ильдар Ялалов on 14.01.2020.
//
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 8e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
typedef unsigned int uint;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()


#ifdef zxc

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

const int MAXN = (2e5 + 100);
const int LOG = 21;
const int mod = 998244353;

int a[MAXN];

void solve() {
    int n;
    cin >> n;
    ll sum[2] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i & 1] += a[i];
    }
    if (sum[1] > sum[0]) {
        for (int i = 1; i <= n; ++i) {
            cout << ((i & 1) ? a[i] : 1) << " ";
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << ((i & 1) ? 1 : a[i]) << " ";
        }
    }
    cout <<"\n";

}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES ( n==1)
signed main() {

#ifdef zxc
    freopen("../output.txt", "r", stdin);
    // freopen("../output3.txt", "w", stdout);
#else
#endif //zxc
    ((void)0);
    ((void)0);
    ((void)0);
    cout.setf(ios::fixed);
    cout.precision(15);


    int t = 1;
    cin >> t;
    while (t--)
        solve();

    debug(1.0 * clock() / CLOCKS_PER_SEC);
}