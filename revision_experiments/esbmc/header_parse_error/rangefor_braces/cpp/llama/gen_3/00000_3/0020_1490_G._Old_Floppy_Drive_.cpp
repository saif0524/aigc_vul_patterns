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
#define ld long double
#define endl "\n"

const int inf = 1e18;
const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (auto &i : a) { cin >> i; }

    vector <int> sum = {0};
    for (auto &i : a) { sum.push_back(sum.back() + i); }
    vector <int> ans;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int l = 0, r = n;

        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (sum[mid] >= x) r = mid;
            else l = mid;
        }

        if (sum[n] <= 0) {
            if (sum[r] >= x) ans.push_back(r);
            else ans.push_back(-1);
        } else {
            int num = max(0LL, (x - sum[r] + sum[n] - 1) / sum[n]);
            int x1 = x - num * sum[n];

            l = 0, r = n;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                if (sum[mid] >= x1) r = mid;
                else l = mid;
            }

            ans.push_back(num * n + r);
        }
    }

    for (auto &i : ans) { cout << i << " "; }
    cout << endl;
}

signed main() {
    ((void)0);
    ((void)0);
    ((void)0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}