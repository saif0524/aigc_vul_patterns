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

const int MAX = 1e6 + 5;

int a[MAX], b[MAX], n, m, q;

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x;
        if (t == 1) {
            a[i - 1] = x;
        } else {
            b[i - 1] = x;
        }
        vector<int> d(n, 0);
        copy(a, a + n, d.begin());
        sort(d.rbegin(), d.rend());
        for (int i = 0; i < m; ++i) {
            auto it = upper_bound(d.begin(), d.end(), b[i]);
            if (it != d.begin()) {
                --d[distance(d.begin(), it)];
            }
        }
        int ans = -1;
        if (!d.empty()) {
            ans = d[0];
        }
        cout << ans << '\n';
    }
    return 0;
}