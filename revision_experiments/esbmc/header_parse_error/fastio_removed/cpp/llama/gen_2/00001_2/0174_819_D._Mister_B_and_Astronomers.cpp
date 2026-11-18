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
#define ld long double

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

ll a[N];
ll x;
ll n;
ll t;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ((void)0);
    ((void)0);

    cin >> t >> n;
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    s = t / gcd(s, t);
    vector<vector<int>> d(n + 1);
    for (int i = 1; i <= n; i++) {
        d[i % n + 1].push_back(((s + a[i]) % t));
    }
    for (int i = 1; i <= n; i++) {
        sort(d[i].begin(), d[i].end());
    }
    vector<pair<int, int>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i % n + 1] = {0, i};
    }
    sort(f.begin() + 1, f.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    for (int i = 1; i <= n; i++) {
        x = max((ll)0, d[i].back() - d[i].front());
        for (int j = 1; j < d[i].size(); j++) {
            x = max(x, d[i][j] - d[i][j - 1] - 1);
        }
        x = max(x, t - d[i].back());
        x = max(x, d[i].front());
        cout << x << ' ';
    }
}