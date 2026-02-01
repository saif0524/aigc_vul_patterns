#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

struct Point {
    double x, y;
};

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double angle(const Point& p) {
    return atan2(p.y, p.x);
}

bool inside(const Point& p, double r, int m, int k) {
    double a = angle(p);
    if (a < 0) a += 2 * PI;
    int idx = int(a / (2 * PI / m));
    double d = dist(p, {0, 0});
    if (d > r) return false;
    if (k == 1) return true;
    double ang = (2 * PI / m) * (idx % k);
    if (a < ang || a >= ang + (2 * PI / m)) return false;
    return true;
}

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        if (n == 0 && m == 0 && k == 0) break;
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        double lo = 0, hi = 1e9;
        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!inside(points[i], mid, m, k)) {
                    ok = false;
                    break;
                }
            }
            if (ok) hi = mid;
            else lo = mid;
        }
        printf("%.10f\n", (lo + hi) / 2);
    }
    return 0;
}