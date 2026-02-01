#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

long long crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool isConvex(const vector<Point>& polygon) {
    int n = polygon.size();
    bool sign = crossProduct(polygon[0], polygon[1], polygon[2]) > 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;
        if (crossProduct(polygon[i], polygon[j], polygon[k]) < 0) {
            if (sign) return false;
        } else if (crossProduct(polygon[i], polygon[j], polygon[k]) > 0) {
            sign = true;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    if (!isConvex(polygon)) {
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    for (int x = min(polygon[0].x, polygon[1].x); x <= max(polygon[0].x, polygon[1].x); x++) {
        Point p = {x, polygon[0].y};
        bool visible = true;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (crossProduct(p, polygon[i], polygon[j]) < 0) {
                visible = false;
                break;
            }
        }
        if (visible) count++;
    }
    cout << count << endl;
    return 0;
}