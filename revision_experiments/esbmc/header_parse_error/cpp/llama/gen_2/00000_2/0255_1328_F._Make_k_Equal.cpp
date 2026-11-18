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

const int N = 2e5 + 5;

int n, k, a[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + k - 1;
        if (r <= n) {
            int mx = a[r];
            int mn = a[l];
            int res = 0;
            for (int j = l - 1; j >= 1; j--) {
                res += mx - a[j];
            }
            for (int j = r + 1; j <= n; j++) {
                res += a[j] - mn;
            }
            ans = min(ans, res);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + k - 1;
        if (r <= n) {
            int mx = a[l];
            int mn = a[r];
            int res = 0;
            for (int j = r + 1; j <= n; j++) {
                res += a[j] - mn;
            }
            for (int j = l - 1; j >= 1; j--) {
                res += mx - a[j];
            }
            ans = min(ans, res);
        }
    }
    printf("%d\n", ans);

    return 0;
}