#include <iostream>
#include <cmath>

using namespace std;

double cross(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

double dot(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1);
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double c1 = cross(x1, y1, x2, y2, x3, y3);
        double c2 = cross(x2, y2, x3, y3, x4, y4);
        double c3 = cross(x3, y3, x4, y4, x1, y1);
        double c4 = cross(x4, y4, x1, y1, x2, y2);
        if (c1 * c2 > 0 && c2 * c3 > 0 && c3 * c4 > 0 && c4 * c1 > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}