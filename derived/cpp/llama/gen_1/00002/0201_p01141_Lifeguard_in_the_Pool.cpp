#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

const double eps = 1e-8;

struct Point {
    double x, y;
};

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double cross(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double get_time(double t1, double t2, const Point& start, const vector<Point>& polygon, const Point& target) {
    double res = numeric_limits<double>::max();
    for (int i = 0; i < polygon.size(); i++) {
        Point a = polygon[i], b = polygon[(i + 1) % polygon.size()];
        Point intersect;
        if (cross(start, target, a) * cross(start, target, b) < 0 && cross(a, b, start) * cross(a, b, target) < 0) {
            intersect.x = (a.x * b.y - a.y * b.x) * (start.x - target.x) - (a.x - b.x) * (start.x * target.y - start.y * target.x);
            intersect.x /= (a.x - b.x) * (start.y - target.y) - (a.y - b.y) * (start.x - target.x);
            intersect.y = (a.x * b.y - a.y * b.x) * (start.y - target.y) - (a.y - b.y) * (start.x * target.y - start.y * target.x);
            intersect.y /= (a.x - b.x) * (start.y - target.y) - (a.y - b.y) * (start.x - target.x);
            res = min(res, t1 * dist(start, intersect) + t2 * dist(intersect, target));
        }
        res = min(res, t1 * (dist(start, a) + dist(a, b)) + t2 * dist(b, target));
        res = min(res, t1 * (dist(start, b) + dist(b, a)) + t2 * dist(a, target));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n != 0) {
        vector<Point> polygon(n);
        for (int i = 0; i < n; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }
        double t1, t2;
        cin >> t1 >> t2;
        Point start, target;
        cin >> start.x >> start.y >> target.x >> target.y;
        double ans = get_time(t1, t2, start, polygon, target);
        cout.precision(10);
        cout << fixed << ans << endl;
    }
    return 0;
}