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

#define int long long

int n, m;
int a[1005][1005];
int pref[1005][1005];

void update(int x, int y, int v) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            pref[i][j] ^= v;
        }
    }
}

int query(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            ans ^= pref[i][j];
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int t, x0, y0, x1, y1, v;
        cin >> t >> x0 >> y0 >> x1 >> y1;

        if (t == 1) {
            int ans = 0;
            for (int i = x0; i <= x1; i++) {
                for (int j = y0; j <= y1; j++) {
                    ans ^= query(i, j);
                }
            }
            cout << ans << "\n";
        } else {
            cin >> v;
            for (int i = x0; i <= x1; i++) {
                for (int j = y0; j <= y1; j++) {
                    update(i, j, v);
                }
            }
        }
    }
}