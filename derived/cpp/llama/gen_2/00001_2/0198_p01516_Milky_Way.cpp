#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const double INF = 1e18;

struct Point {
    double x, y;
};

struct Star {
    Point center;
    double angle, radius;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double intersect(const Star& s1, const Star& s2) {
    double dx = s2.center.x - s1.center.x;
    double dy = s2.center.y - s1.center.y;
    double d = sqrt(dx * dx + dy * dy);
    if (d > s1.radius + s2.radius + EPS) return INF;
    if (d < abs(s1.radius - s2.radius) - EPS) return INF;
    double a = (s1.radius * s1.radius - s2.radius * s2.radius + d * d) / (2 * d);
    double h = sqrt(s1.radius * s1.radius - a * a);
    double xm = s1.center.x + a * dx / d;
    double ym = s1.center.y + a * dy / d;
    double xs1 = xm + h * dy / d;
    double xs2 = xm - h * dy / d;
    double ys1 = ym - h * dx / d;
    double ys2 = ym + h * dx / d;
    double p1 = atan2(ys1 - s1.center.y, xs1 - s1.center.x);
    double p2 = atan2(ys2 - s1.center.y, xs2 - s1.center.x);
    if (p1 < s1.angle - EPS || p1 > s1.angle + EPS) return INF;
    if (p2 < s1.angle - EPS || p2 > s1.angle + EPS) return INF;
    double q1 = atan2(ys1 - s2.center.y, xs1 - s2.center.x);
    double q2 = atan2(ys2 - s2.center.y, xs2 - s2.center.x);
    if (q1 < s2.angle - EPS || q1 > s2.angle + EPS) return INF;
    if (q2 < s2.angle - EPS || q2 > s2.angle + EPS) return INF;
    return sqrt((xs1 - s1.center.x) * (xs1 - s1.center.x) + (ys1 - s1.center.y) * (ys1 - s1.center.y));
}

int main() {
    int n, m, l;
    while (cin >> n >> m >> l) {
        if (n == 0 && m == 0 && l == 0) break;
        vector<Star> stars(n);
        for (int i = 0; i < n; i++) {
            double x, y, a, r;
            cin >> x >> y >> a >> r;
            stars[i].center = {x, y};
            stars[i].angle = a * PI / 180;
            stars[i].radius = r;
        }
        double res = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double d = intersect(stars[m - 1], stars[i]);
                if (d < res - EPS) {
                    res = d;
                }
                d += distance(stars[i].center, stars[j].center);
                d += intersect(stars[j], stars[l - 1]);
                if (d < res - EPS) {
                    res = d;
                }
            }
        }
        if (res > INF / 2) res = 0;
        cout << fixed;
        cout.precision(18);
        cout << res << endl;
    }
    return 0;
}