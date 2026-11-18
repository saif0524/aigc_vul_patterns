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

const int mod = 1e9 + 7;

int main() {
    ((void)0);
    ((void)0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        if (x < 0) {
            w[-x - 1] = y;
        } else {
            ll sum = 0;
            int l = x - 1, r = y - 1;

            int mid = (l + r) / 2;
            for (int i = l; i <= r; i++) {
                sum = (sum + abs(a[i] - a[mid]) * (ll)w[i]) % mod;
            }
            cout << sum << "\n";
        }
    }

    return 0;
}