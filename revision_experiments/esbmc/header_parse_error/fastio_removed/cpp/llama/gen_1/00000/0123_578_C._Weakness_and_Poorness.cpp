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

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n;
int a[MAXN];

double f(double x) {
    double mx = 0.0;
    for (int i = 0; i < n; i++) {
        double s = 0.0;
        for (int j = i; j < n; j++) {
            s += a[j] - x;
            mx = max(mx, abs(s));
        }
    }
    return mx;
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double l = *min_element(a, a + n) - 1e6;
    double r = *max_element(a, a + n) + 1e6;

    for (int it = 0; it < 100; it++) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        if (f(m1) < f(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }

    cout << fixed << setprecision(9) << f((l + r) / 2.0) << '\n';

    return 0;
}