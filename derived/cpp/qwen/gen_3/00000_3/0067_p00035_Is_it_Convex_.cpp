#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double cross(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool isConvex(const Point &a, const Point &b, const Point &c, const Point &d) {
    int c1 = cross(a, b, c) > 0;
    int c2 = cross(b, c, d) > 0;
    int c3 = cross(c, d, a) > 0;
    int c4 = cross(d, a, b) > 0;
    return (c1 == c2 && c2 == c3 && c3 == c4);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    double xa, ya, xb, yb, xc, yc, xd, yd;
    while (cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd) {
        Point a = {xa, ya};
        Point b = {xb, yb};
        Point c = {xc, yc};
        Point d = {xd, yd};
        if (isConvex(a, b, c, d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}