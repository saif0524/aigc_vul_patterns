#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isVisible(Point tower, Point criminal, const vector<Point>& polygon) {
    for (size_t i = 0; i < polygon.size(); ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % polygon.size()];

        // Check if the line segment between tower and criminal intersects with the edge p1-p2
        if ((p1.y > min(tower.y, criminal.y) && p1.y < max(tower.y, criminal.y)) &&
            (p2.y > min(tower.y, criminal.y) && p2.y < max(tower.y, criminal.y)) &&
            (p1.x > min(tower.x, criminal.x) && p1.x < max(tower.x, criminal.x)) &&
            (p2.x > min(tower.x, criminal.x) && p2.x < max(tower.x, criminal.x))) {

            // Calculate the intersection point
            double den = (double)(tower.y - criminal.y) * (p2.x - p1.x) - (double)(tower.x - criminal.x) * (p2.y - p1.y);
            if (den == 0) continue;

            double t = (double)((tower.x - p1.x) * (p2.y - p1.y) - (tower.y - p1.y) * (p2.x - p1.x)) / den;
            double u = -((double)(tower.x - criminal.x) * (p2.y - p1.y) - (tower.y - criminal.y) * (p2.x - p1.x)) / den;

            if (t > 0 && t < 1 && u > 0 && u < 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point a = polygon[0];
    Point b = polygon[1];

    int count = 0;
    for (int x = min(a.x, b.x); x <= max(a.x, b.x); ++x) {
        Point tower = {x, a.y};
        bool valid = true;
        for (int i = 2; i < n; ++i) {
            if (!isVisible(tower, polygon[i], polygon)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}