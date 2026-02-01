#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point& other) { return Point(x + other.x, y + other.y); }
    Point operator-(const Point& other) { return Point(x - other.x, y - other.y); }
    double operator*(const Point& other) { return x * other.x + y * other.y; }
    double operator%(const Point& other) { return x * other.y - y * other.x; }
    double norm() { return x * x + y * y; }
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1 - p2).norm());
}

bool is_collinear(const Point& p1, const Point& p2, const Point& p3) {
    return fabs((p2 - p1) % (p3 - p1)) < EPS;
}

bool is_on_segment(const Point& p1, const Point& p2, const Point& p3) {
    return is_collinear(p1, p2, p3) && (p2 - p1) * (p2 - p3) < 0;
}

bool do_intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double o1 = (p1 - p2) % (p3 - p1);
    double o2 = (p1 - p2) % (p4 - p1);
    double o3 = (p3 - p4) % (p1 - p3);
    double o4 = (p3 - p4) % (p2 - p3);
    return o1 * o2 < 0 && o3 * o4 < 0;
}

double circle_line_distance(const Point& center, double radius, const Point& p1, const Point& p2) {
    Point v = p2 - p1;
    double d = v.norm();
    Point w = center - p1;
    double t = w * v / d;
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    Point q = p1 + v * t;
    return distance(center, q) - radius;
}

void testcase() {
    int n;
    cin >> n;
    Point c1, c2;
    double r1, r2;
    cin >> c1.x >> c1.y >> r1;
    cin >> c2.x >> c2.y >> r2;
    vector<Point> red(n), blue(n);
    for (auto& p : red) {
        cin >> p.x >> p.y;
    }
    for (auto& p : blue) {
        cin >> p.x >> p.y;
    }

    double ans = 0.0;
    bool impossible = false;
    for (int i = 0; i < n; i++) {
        double min_dist = 1e9;
        int min_j = -1;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            Point v = blue[j] - red[i];
            double d = v.norm();
            Point w = c1 - red[i];
            double t1 = w * v / d;
            w = c2 - red[i];
            double t2 = w * v / d;
            if (t1 < 0) t1 = 0;
            if (t1 > 1) t1 = 1;
            if (t2 < 0) t2 = 0;
            if (t2 > 1) t2 = 1;
            Point q1 = red[i] + v * t1;
            Point q2 = red[i] + v * t2;
            double dist = distance(blue[j], q1) + distance(red[i], q1) + distance(blue[j], q2) + distance(red[i], q2);
            if (circle_line_distance(c1, r1, red[i], blue[j]) < 0 || circle_line_distance(c2, r2, red[i], blue[j]) < 0) {
                continue;
            }
            if (dist < min_dist) {
                min_dist = dist;
                min_j = j;
            }
        }
        if (min_j == -1) {
            impossible = true;
            break;
        }
        ans += min_dist;
        swap(blue[min_j], blue[i]);
    }
    if (impossible) {
        cout << "Impossible\n";
    } else {
        cout << fixed;
        cout.precision(10);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    testcase();
    return 0;
}