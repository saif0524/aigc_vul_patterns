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

#define ll long long
#define INF 1e18
#define MOD 1000000007
#define MAXN 100005

int n, k;
ll a[MAXN];
bool ok;

ll sum(ll l, ll r) {
    ll s = 0;
    for (ll i = l; i <= r; i++) {
        s += a[i];
    }
    return s;
}

void check() {
    for (ll i = 1; i <= n - k + 1; i++) {
        if (sum(i, i + k - 1) >= sum(i + 1, i + k)) {
            ok = false;
            return;
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> k;
    ok = true;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "?") {
            a[i] = 0;
        } else {
            a[i] = stoll(s);
        }
    }

    for (ll i = 1; i <= n - k + 1; i++) {
        ll x = sum(i + 1, i + k - 1) - sum(i, i + k - 2);
        if (a[i] == 0) {
            a[i] = x;
        } else if (a[i] != x) {
            ok = false;
            break;
        }
    }

    if (ok) {
        check();
        if (!ok) {
            cout << "Incorrect sequence\n";
        } else {
            for (ll i = 1; i <= n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "Incorrect sequence\n";
    }

    return 0;
}