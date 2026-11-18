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

const int MAXN = 1e5 + 5;

int n, a[MAXN], b[MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        s.insert(c[i]);
    }

    int ans = 1e9;

    for (int u = 0; u <= n; u++) {
        set<int> au;
        for (int i = 0; i < u; i++) {
            au.insert(a[i]);
        }

        for (int v = 0; v <= n; v++) {
            set<int> bu;
            for (int i = 0; i < v; i++) {
                bu.insert(b[i]);
            }

            for (int w = 0; w <= n; w++) {
                set<int> cu;
                for (int i = 0; i < w; i++) {
                    cu.insert(c[i]);
                }

                set<int> all;
                for (auto x : au) all.insert(x);
                for (auto x : bu) all.insert(x);
                for (auto x : cu) all.insert(x);

                if (all.size() == s.size()) {
                    ans = min(ans, u + v + w);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}