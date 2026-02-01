#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dot(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

double solve(const vector<Point>& poly, double tg, double tw, const Point& start, const Point& target) {
    int n = poly.size();
    double ans = numeric_limits<double>::max();

    for (int i = 0; i < n; ++i) {
        Point a = poly[i];
        Point b = poly[(i + 1) % n];

        if (cross(start, a, b) >= 0 && cross(target, a, b) >= 0) {
            double t = (dot(start, a, b) * dot(target, a, b)) / (dot(a, b, b) * dot(a, b, b));
            Point p;
            p.x = a.x + t * (b.x - a.x);
            p.y = a.y + t * (b.y - a.y);

            ans = min(ans, tg * dist(start, p) + tw * dist(p, target));
        }
    }

    for (int i = 0; i < n; ++i) {
        Point a = poly[i];
        Point b = poly[(i + 1) % n];

        if (cross(start, a, b) <= 0 && cross(target, a, b) <= 0) {
            ans = min(ans, tg * dist(start, a) + tw * dist(a, target));
            ans = min(ans, tg * dist(start, b) + tw * dist(b, target));
        }
    }

    return ans;
}

int main() {
    int n;
    while (cin >> n && n!= 0) {
        vector<Point> poly(n);
        for (int i = 0; i < n; ++i) {
            cin >> poly[i].x >> poly[i].y;
        }

        double tg, tw;
        cin >> tg >> tw;

        Point start, target;
        cin >> start.x >> start.y >> target.x >> target.y;

        cout << fixed;
        cout.precision(8);
        cout << solve(poly, tg, tw, start, target) << endl;
    }

    return 0;
}