#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n;
    double px, py;
    cin >> n >> px >> py;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double r = 0;
    for (int i = 0; i < n; i++) {
        r = max(r, dist(points[i], {px, py}));
    }

    double area = PI * r * r;
    cout << fixed;
    cout.precision(17);
    cout << area << endl;

    return 0;
}