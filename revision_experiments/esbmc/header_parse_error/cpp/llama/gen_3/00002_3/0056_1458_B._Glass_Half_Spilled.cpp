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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }

    vector<double> ans(n);
    for (int k = 1; k <= n; k++) {
        double mx = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask)!= k) continue;
            double cur = 0;
            int cnt = 0, cap = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur += b[i];
                    cap += a[i];
                    cnt++;
                }
            }
            cur = min(cap, cur + (sum - cur) / 2.0);
            mx = max(mx, cur);
        }
        ans[k-1] = mx;
    }

    for (double x : ans) {
        printf("%.10f ", x);
    }
    return 0;
}