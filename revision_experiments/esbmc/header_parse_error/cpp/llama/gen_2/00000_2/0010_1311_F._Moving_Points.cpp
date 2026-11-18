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
    long long x, v, id;

    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x;
        points[i].id = i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> points[i].v;
    }

    sort(points.begin(), points.end());

    long long total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = iivic + 1; j < n; ++j) {
            long long dx = points[j].x - points[i].x;
            long long dv = points[j].v - points[i].v;

            if (dv == 0) {
                total += dx;
            } else {
                long long t = dx / dv;
                if (t * dv * dv > dx * dx) {
                    total += abs(dx);
                } else {
                    total += abs(dx - t * dv);
                }
            }
        }
    }

    cout << total << '\n';

    return 0;
}