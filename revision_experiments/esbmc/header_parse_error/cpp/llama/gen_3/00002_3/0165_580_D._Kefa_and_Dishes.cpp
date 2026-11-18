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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> rules(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        rules[x - 1][y - 1] = c;
    }

    vector<vector<long long>> dp((1 << n), vector<long long>(n, -1));

    function<long long(int, int)> go = [&](int mask, int last) {
        if (__builtin_popcount(mask) == m) return 0;
        if (dp[mask][last] != -1) return dp[mask][last];

        long long max_val = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                long long new_val = a[i] + go(mask | (1 << i), i);
                if (last != -1) new_val += rules[last][i];
                max_val = max(max_val, new_val);
            }
        }
        return dp[mask][last] = max_val;
    };

    cout << go(0, -1) << '\n';

    return 0;
}