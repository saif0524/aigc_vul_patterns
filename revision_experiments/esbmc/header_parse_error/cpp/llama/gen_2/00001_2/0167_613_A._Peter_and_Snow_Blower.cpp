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
typedef long double ld;
typedef long long ll;
const int maxn = 200005;
int n;
int P[2];
pair<int, int> a[maxn];

ld sqr(ld x) {
    return x * x;
}

ld dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(sqr(b.first - a.first) + sqr(b.second - a.second));
}

const ld pi = acos(-1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> P[0] >> P[1];
    ld minr = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        ld d = dist({P[0], P[1]}, {a[i].first, a[i].second});
        minr = min(minr, d);
    }
    cout.precision(20);
    cout << fixed << pi * minr * minr << endl;
    return 0;
}