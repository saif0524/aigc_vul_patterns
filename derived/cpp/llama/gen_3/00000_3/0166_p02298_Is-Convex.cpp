#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

long long crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    bool isConvex = true;
    for (int i = 0; i < n; i++) {
        const Point& p1 = points[(i - 1 + n) % n];
        const Point& p2 = points[i];
        const Point& p3 = points[(i + 1) % n];
        long long cross = crossProduct(p1, p2, p3);
        if (i == 0) {
            if (cross > 0) {
                isConvex = false;
            }
        } else if (cross != 0 && crossProduct(points[0], points[1], points[2]) * cross < 0) {
            isConvex = false;
            break;
        }
    }

    cout << (isConvex ? 1 : 0) << endl;

    return 0;
}