#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Point {
    long long x, y;
    Point() {}
    Point(long long x, long long y) : x(x), y(y) {}
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

long long cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long long dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

bool in(const Point &p, const vector<Point> &poly) {
    int n = poly.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (cross(poly[j] - poly[i], p - poly[i]) > 0) {
            if (poly[i].y <= p.y && p.y < poly[j].y) {
                double t = (double)(p.y - poly[i].y) / (poly[j].y - poly[i].y);
                if (poly[i].x + t * (poly[j].x - poly[i].x) <= p.x) {
                    cnt++;
                }
            }
        }
        if (cross(poly[j] - poly[i], p - poly[i]) < 0) {
            if (poly[j].y <= p.y && p.y < poly[i].y) {
                double t = (double)(p.y - poly[j].y) / (poly[i].y - poly[j].y);
                if (poly[j].x + t * (poly[i].x - poly[j].x) <= p.x) {
                    cnt++;
                }
            }
        }
    }
    return cnt % 2 == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> poly(n);
    for (auto &p : poly) {
        cin >> p.x >> p.y;
    }

    vector<Point> points;
    for (int dx = -10; dx <= 10; dx++) {
        for (int dy = -10; dy <= 10; dy++) {
            Point dv(dx, dy);
            for (int i = 0; i < n; i++) {
                Point p = poly[i] + dv;
                if (in(p, poly)) {
                    points.push_back(p);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        points.push_back(poly[i]);
    }

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    });

    points.erase(unique(points.begin(), points.end()), points.end());

    long long cnt = points.size();
    long long sum = 0;

    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            Point p = points[i];
            Point q = points[j];
            sum += (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
        }
    }

    double ans = (double)sum / (cnt * (cnt - 1) / 2);

    cout.precision(20);
    cout << fixed << ans << '\n';

    return 0;
}