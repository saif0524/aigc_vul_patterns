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

const double PI = acos(-1.0);
const double EPS = 1e-9;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator-(const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }
    Point operator+(const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); }
    Point operator*(const double &rhs) const { return Point(x * rhs, y * rhs); }
    double dot(const Point &rhs) const { return x * rhs.x + y * rhs.y; }
    double cross(const Point &rhs) const { return x * rhs.y - y * rhs.x; }
    double length() const { return sqrtl(x * x + y * y); }
};

struct Line {
    Point p1, p2;
    Line(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
    double distance(const Point &p) const {
        return fabs((p2 - p1).cross(p - p1)) / (p2 - p1).length();
    }
};

vector<Line> lines;
vector<pair<Point, Point>> roads;

bool intersect(const Line &l1, const Line &l2, Point &p) {
    double d1 = l1.p2.x * l1.p1.y - l1.p1.x * l1.p2.y;
    double d2 = l2.p2.x * l2.p1.y - l2.p1.x * l2.p2.y;
    double d3 = l1.p2.x - l1.p1.x;
    double d4 = l1.p2.y - l1.p1.y;
    double d5 = l2.p2.x - l2.p1.x;
    double d6 = l2.p2.y - l2.p1.y;

    double t = (d5 * d1 - d2 * d3) / (d3 * d6 - d4 * d5);
    double u = (d6 * d1 - d4 * d2) / (d3 * d6 - d4 * d5);

    if (fabs(t) < EPS && fabs(u) < EPS) return false;

    p = Point(l1.p1.x + t * d3, l1.p1.y + t * d4);
    return true;
}

double calculateShade(const Point &p1, const Point &p2, const Line &line) {
    Point p;
    if (!intersect(Line(p1, p2), line, p)) return 0;
    if ((p - p1).dot(p2 - p1) < -EPS || (p - p2).dot(p1 - p2) > EPS) return 0;
    return (p2 - p1).length();
}

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<double> heights(n);
        vector<vector<Point>> polygons(n);

        for (int i = 0; i < n; i++) {
            int nv;
            cin >> nv >> heights[i];
            polygons[i].resize(nv);
            for (int j = 0; j < nv; j++) {
                cin >> polygons[i][j].x >> polygons[i][j].y;
            }
        }

        roads.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> roads[i].first.x >> roads[i].first.y >> roads[i].second.x >> roads[i].second.y;
        }

        double theta, phi;
        cin >> theta >> phi;

        Point s, t;
        cin >> s.x >> s.y >> t.x >> t.y;

        theta = theta * PI / 180;
        phi = phi * PI / 180;

        Point sunDir(cos(theta), sin(theta));

        for (int i = 0; i < n; i++) {
            int nv = polygons[i].size();
            for (int j = 0; j < nv; j++) {
                Point p1 = polygons[i][j];
                Point p2 = polygons[i][(j + 1) % nv];

                Point shadeDir = (p2 - p1);
                shadeDir = Point(-shadeDir.y, shadeDir.x);

                double dot = shadeDir.dot(sunDir);
                if (dot < -EPS) continue;

                double len = (p2 - p1).length();
                Point mid = (p1 + p2) * 0.5;

                Point top = mid + shadeDir * heights[i] / tan(phi);

                lines.push_back(Line(mid, top));
            }
        }

        double ans = 1e18;

        for (int i = 0; i < m; i++) {
            double dist = roads[i].first.distance(s) + roads[i].second.distance(t) + (roads[i].second - roads[i].first).length();
            for (const auto &line : lines) {
                dist -= calculateShade(roads[i].first, roads[i].second, line);
            }
            ans = min(ans, dist);
        }

        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}