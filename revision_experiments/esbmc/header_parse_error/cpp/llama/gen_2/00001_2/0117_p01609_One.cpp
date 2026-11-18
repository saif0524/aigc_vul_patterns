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

const double eps = 1e-8;

struct Point {
    double x, y;
};

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x;
}

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calc(double a, double p, double q, double x) {
    return a * (x - p) * (x - p) + q;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<tuple<double, double, double>> peaks(N);
    for (auto &[a, p, q] : peaks) {
        cin >> a >> p >> q;
    }

    vector<Point> boundary;
    for (int i = 0; i < N; i++) {
        auto [a, p, q] = peaks[i];
        double x = 0;
        while (x <= W) {
            double y = calc(a, p, q, x);
            if (y <= H) {
                boundary.push_back({x, y});
            }
            x += 1;
        }
    }

    for (int i = 0; i < N; i++) {
        auto [a, p, q] = peaks[i];
        double x = W;
        while (x >= 0) {
            double y = calc(a, p, q, x);
            if (y <= H) {
                boundary.push_back({x, y});
            }
            x -= 1;
        }
    }

    sort(boundary.begin(), boundary.end());

    vector<Point> convex_hull;
    for (const auto &p : boundary) {
        while (convex_hull.size() >= 2) {
            const auto &q = convex_hull[convex_hull.size() - 1];
            const auto &r = convex_hull[convex_hull.size() - 2];
            if ((q.x - r.x) * (p.y - r.y) - (q.y - r.y) * (p.x - r.x) >= 0) {
                convex_hull.pop_back();
            } else {
                break;
            }
        }
        convex_hull.push_back(p);
    }

    double ans = 0;
    for (int i = 0; i < convex_hull.size() - 1; i++) {
        ans += dist(convex_hull[i], convex_hull[i + 1]);
    }

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}