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
typedef double db;

const db EPS = 1e-6;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
    ll operator*(const Point& b) const { return x * b.y - y * b.x; }
};

ll area2(const vector<Point>& pts) {
    ll res = 0;
    int n = pts.size();
    for (int i = 0; i < n; ++i) {
        res += pts[i] * pts[(i + 1) % n];
    }
    return abs(res);
}

ll countPoints(const vector<Point>& pts) {
    ll inside = 0;
    int n = pts.size();
    for (int i = 0; i < n; ++i) {
        ll A = area2({0, 0, pts[(i + 1) % n]}) + area2({0, pts[i], pts[(i + 1) % n]}) - area2({0, pts[i], {0, 0}});
        inside += (A + pts[i] * pts[(i + 1) % n]) / 2;
    }
    return inside + n;
}

ll dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

db expectedArea(const vector<Point>& pts) {
    ll n = pts.size();
    ll totalPoints = countPoints(pts);
    ll area = area2(pts);
    db sumOfSquares = 0;

    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            Point v = pts[j] - pts[i];
            db d2 = dot(v, v);
            sumOfSquares += d2;
        }
    }

    return sumOfSquares / 3 / (totalPoints * (totalPoints - 1)) * 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> pts(n);
    for(auto &p : pts) cin >> p.x >> p.y;
    cout << fixed << setprecision(10) << expectedArea(pts) << endl;
}