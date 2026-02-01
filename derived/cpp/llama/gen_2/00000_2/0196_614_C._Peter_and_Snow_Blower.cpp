#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    double px, py;
    cin >> n >> px >> py;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double maxDist = 0;
    for (int i = 0; i < n; i++) {
        maxDist = max(maxDist, dist(points[i], {px, py}));
    }

    cout.precision(20);
    cout << fixed << M_PI * maxDist * maxDist << endl;

    return 0;
}