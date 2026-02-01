#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;

struct Point {
    double x, y;
};

bool cmp(const Point &a, const Point &b) {
    return a.x < b.x;
}

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double solve(const vector<Point> &poly, double w, double v, double u) {
    int n = poly.size();
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back()) <= cross(hull[hull.size() - 2], poly[i])) {
            hull.pop_back();
        }
        hull.push_back(poly[i]);
    }
    double lo = 0, hi = 1e9;
    for (int it = 0; it < 100; it++) {
        double mid = (lo + hi) / 2;
        bool ok = true;
        for (int i = 0; i < hull.size(); i++) {
            int j = (i + 1) % hull.size();
            double dx = hull[j].x - hull[i].x;
            double dy = hull[j].y - hull[i].y;
            double t = (hull[i].x + eps) / v;
            double y = hull[i].y + (mid - t) * u;
            if (y < hull[i].y + (mid - t) * (dy / dx) * v) {
                ok = false;
                break;
            }
            if (y > w) {
                ok = false;
                break;
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    int n, w, v, u;
    cin >> n >> w >> v >> u;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }
    sort(poly.begin(), poly.end(), cmp);
    cout << fixed;
    cout.precision(10);
    cout << solve(poly, w, v, u) << endl;
    return 0;
}