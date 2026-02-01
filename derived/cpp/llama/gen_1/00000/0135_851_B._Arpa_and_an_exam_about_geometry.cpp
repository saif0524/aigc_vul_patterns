#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

long long Cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

long long Dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;

    if (Cross(ab, bc) == 0 && Cross(ab, ca) == 0) {
        if (Dot(ab, bc) == 0 && Dot(ab, ca) == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        return 0;
    }

    Point p;
    p.x = (Cross(ca, ab) + Cross(ab, bc)) / (2 * Cross(ab, bc));
    p.y = (Dot(ca, ab) + Dot(ab, bc)) / (2 * Cross(ab, bc));

    Point ap = p - a;
    Point bp = p - b;
    Point cp = p - c;

    if (Cross(ap, bp) == Cross(bp, cp) && Cross(ap, bp) != 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}