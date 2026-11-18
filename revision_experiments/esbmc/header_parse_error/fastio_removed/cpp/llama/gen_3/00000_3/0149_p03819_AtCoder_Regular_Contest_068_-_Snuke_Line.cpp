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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals(n);
    for (auto& [l, r] : intervals) {
        cin >> l >> r;
    }

    for (int d = 1; d <= m; ++d) {
        int count = 0;
        for (const auto& [l, r] : intervals) {
            if (l % d == 0 || (r - l + 1) / d > 0 && (l - 1) % d + 1 <= (r - l + 1) / d) {
                count++;
            }
        }
        cout << count << '\n';
    }
}

int main() {
    ((void)0);
    ((void)0);
    solve();
    return 0;
}