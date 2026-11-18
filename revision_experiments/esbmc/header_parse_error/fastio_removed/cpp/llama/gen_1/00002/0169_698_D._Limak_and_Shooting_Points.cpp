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
typedef pair<int, int> pii;

ll cross(const pii& a, const pii& b, const pii& c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main() {
    ((void)0);
    ((void)0);

    int k, n;
    cin >> k >> n;

    vector<pii> ax(k), mx(n);
    for (int i = 0; i < k; i++) cin >> ax[i].first >> ax[i].second;
    for (int i = 0; i < n; i++) cin >> mx[i].first >> mx[i].second;

    vector<bool> afraid(n, false);
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<pii> used;
        for (int i = 0; i < k; i++) if (mask & (1 << i)) used.push_back(ax[i]);

        for (int i = 0; i < n; i++) {
            bool good = false;
            for (auto& p : used) {
                bool left = true, right = true;
                for (auto& q : used) {
                    if (q != p) {
                        ll c = cross(p, mx[i], q);
                        if (c > 0) left = false;
                        if (c < 0) right = false;
                    }
                }
                if (left || right) {
                    good = true;
                    break;
                }
            }
            afraid[i] = afraid[i] || good;
        }
    }

    int ans = 0;
    for (bool b : afraid) ans += b;
    cout << ans << '\n';

    return 0;
}