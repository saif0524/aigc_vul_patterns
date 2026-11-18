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

ll area(ll x1, ll y1, ll x2, ll y2) {
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll total_cells = n * m;
        ll white_spill = area(x1, y1, x2, y2);
        ll black_spill = area(x3, y3, x4, y4);
        ll overlap = max(0LL, min(x2, x4) - max(x1, x3) + 1) * max(0LL, min(y2, y4) - max(y1, y3) + 1);
        ll only_white = white_spill - overlap;
        ll only_black = black_spill - overlap;
        ll total_covered = only_white + only_black + overlap;
        ll white_cells = only_white + overlap;
        ll black_cells = only_black + overlap;
        if (only_white < 0) only_white = 0;
        if (only_black < 0) only_black = 0;
        if (overlap < 0) overlap = 0;
        white_cells = white_spill - overlap;
        black_cells = total_cells - white_spill + overlap;
        cout << white_cells << " " << black_cells << "\n";
    }
}