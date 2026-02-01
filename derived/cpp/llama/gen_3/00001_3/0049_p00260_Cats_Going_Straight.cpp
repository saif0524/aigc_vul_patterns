#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int cross(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int dot(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}

int main() {
    int n;
    while (cin >> n && n!= 0) {
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        int ans = n;
        for (int mask = 1; mask < (1 << n); mask++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    bool found = false;
                    for (int j = 0; j < n; j++) {
                        if (mask & (1 << j)) {
                            if (cross(points[i], points[(i + 1) % n], points[j]) >= 0 &&
                                cross(points[i], points[(i + n - 1) % n], points[j]) <= 0 &&
                                dot(points[i], points[(i + 1) % n], points[j]) >= 0 &&
                                dot(points[i], points[(i + n - 1) % n], points[j]) >= 0) {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                ans = min(ans, __builtin_popcount(mask));
            }
        }
        cout << ans << endl;
    }
    return 0;
}