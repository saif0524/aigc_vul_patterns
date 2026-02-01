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
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back()) <= cross(poly[i], hull.back())) {
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
            Point p = hull[j];
            p.x -= v * mid;
            double dx = hull[i].x - hull[j].x;
            double dy = hull[i].y - hull[j].y;
            double a = dx * dx + dy * dy;
            double b = 2 * (dx * (hull[i].x - p.x) + dy * (hull[i].y - p.y));
            double c = (hull[i].x - p.x) * (hull[i].x - p.x) + (hull[i].y - p.y) * (hull[i].y - p.y) - w * w;
            double D = b * b - 4 * a * c;
            if (D >= 0) {
                double t = (-b - sqrt(D)) / (2 * a);
                if (t >= 0 && t <= 1) {
                    double yy = hull[i].y + t * dy;
                    if (yy <= u * mid + eps) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return (lo + hi) / 2;
}

int main() {
    int n, w, v, u;
    cin >> n >> w >> v >> u;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }
    sort(poly.begin(), poly.end(), cmp);
    double ans = solve(poly, w, v, u);
    printf("%.12f\n", ans);
    return 0;
}