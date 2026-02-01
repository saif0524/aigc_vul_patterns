#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const long double eps = 1e-12;

struct Point {
    long long x, y;
};

long long cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long dot(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

long double area(const Point& a, const Point& b, const Point& c) {
    return abs(cross(a, b, c)) / 2.0;
}

long double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double sq(long double x) {
    return x * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long total = 0;
    long double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_y2 = 0;

    for (int x = points[0].x; x <= points[0].x; ++x) {
        for (int y = points[0].y; y <= points[0].y; ++y) {
            Point p = {x, y};
            bool inside = true;
            for (int i = 0; i < n; ++i) {
                if (cross(points[i], points[(i + 1) % n], p) < 0) {
                    inside = false;
                    break;
                }
            }
            if (inside) {
                total++;
                sum_x += x;
                sum_y += y;
                sum_x2 += sq(x);
                sum_y2 += sq(y);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int x1 = points[i].x, y1 = points[i].y;
        int x2 = points[(i + 1) % n].x, y2 = points[(i + 1) % n].y;

        long long dx = x2 - x1, dy = y2 - y1;
        long long len = abs(dx) + abs(dy);

        for (int j = 0; j < len; ++j) {
            int x = x1 + dx * j / len, y = y1 + dy * j / len;
            if (x == x1 && y == y1) continue;
            Point p = {x, y};
            bool inside = true;
            for (int k = 0; k < n; ++k) {
                if (cross(points[k], points[(k + 1) % n], p) < 0) {
                    inside = false;
                    break;
                }
            }
            if (inside) {
                total++;
                sum_x += x;
                sum_y += y;
                sum_x2 += sq(x);
                sum_y2 += sq(y);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int x1 = points[i].x, y1 = points[i].y;
        int x2 = points[(i + 1) % n].x, y2 = points[(i + 1) % n].y;

        long long dx = x2 - x1, dy = y2 - y1;
        long long len = abs(dx) + abs(dy);

        for (int j = 1; j < len; ++j) {
            int x = x1 + dx * j / len, y = y1 + dy * j / len;
            Point p = {x, y};
            bool inside = true;
            for (int k = 0; k < n; ++k) {
                if (cross(points[k], points[(k + 1) % n], p) < 0) {
                    inside = false;
                    break;
                }
            }
            if (inside) {
                total++;
                sum_x += x;
                sum_y += y;
                sum_x2 += sq(x);
                sum_y2 += sq(y);
            }
        }
    }

    for (int x = points[0].x; x <= points[0].x; ++x) {
        for (int y = points[0].y; y <= points[0].y; ++y) {
            Point p = {x, y};
            bool inside = true;
            for (int i = 0; i < n; ++i) {
                if (cross(points[i], points[(i + 1) % n], p) < 0) {
                    inside = false;
                    break;
                }
            }
            if (inside) {
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        Point q = {x + dx, y + dy};
                        bool inside2 = true;
                        for (int i = 0; i < n; ++i) {
                            if (cross(points[i], points[(i + 1) % n], q) < 0) {
                                inside2 = false;
                                break;
                            }
                        }
                        if (inside2) {
                            total++;
                            sum_x += x;
                            sum_y += y;
                            sum_x2 += sq(x);
                            sum_y2 += sq(y);
                        }
                    }
                }
            }
        }
    }

    long double ans = (2.0 * (sum_x2 + sum_y2) - 2.0 * (sum_x * sum_x + sum_y * sum_y) / total) / (total * (total - 1));

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}