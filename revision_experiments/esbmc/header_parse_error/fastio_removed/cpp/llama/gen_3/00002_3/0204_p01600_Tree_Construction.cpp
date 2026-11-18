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

struct Point {
    int x, y;
    bool operator<(const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y > rhs.y);
    }
};

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto &p : points) {
        cin >> p.x >> p.y;
    }

    sort(points.begin(), points.end());

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            if (dx >= 0 && dy <= 0) {
                dp[i] = min(dp[i], dp[j] + dx - dy);
            }
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}