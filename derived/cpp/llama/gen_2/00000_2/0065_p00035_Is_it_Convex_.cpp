#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool isConvex(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double cp1 = crossProduct(p1, p2, p3);
    double cp2 = crossProduct(p2, p3, p4);
    double cp3 = crossProduct(p3, p4, p1);
    double cp4 = crossProduct(p4, p1, p2);

    return (cp1 >= 0 && cp2 >= 0 && cp3 >= 0 && cp4 >= 0) ||
           (cp1 <= 0 && cp2 <= 0 && cp3 <= 0 && cp4 <= 0);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

        if (isConvex(p1, p2, p3, p4)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}