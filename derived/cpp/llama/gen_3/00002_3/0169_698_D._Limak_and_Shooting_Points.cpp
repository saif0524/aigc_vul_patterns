#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

long long cross(const Point &o, const Point &a, const Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

bool cmp(const Point &a, const Point &b) {
    return a.x == b.x? a.y < b.y : a.x < b.x;
}

vector<Point> convexHull(vector<Point> &points) {
    int n = points.size();
    if (n < 3) return {};
    sort(points.begin(), points.end(), cmp);
    vector<Point> up, down;
    for (int i = 0; i < n; i++) {
        while (up.size() >= 2 && cross(up[up.size() - 2], up.back(), points[i]) > 0)
            up.pop_back();
        up.push_back(points[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (down.size() >= 2 && cross(down[down.size() - 2], down.back(), points[i]) > 0)
            down.pop_back();
        down.push_back(points[i]);
    }
    up.pop_back();
    down.pop_back();
    up.insert(up.end(), down.begin(), down.end());
    return up;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<Point> points(k);
    for (int i = 0; i < k; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<Point> monsters(n);
    for (int i = 0; i < n; i++) {
        cin >> monsters[i].x >> monsters[i].y;
    }
    set<int> afraid;
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<Point> currPoints;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                currPoints.push_back(points[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            currPoints.push_back(monsters[i]);
        }
        vector<Point> hull = convexHull(currPoints);
        for (int i = 0; i < hull.size(); i++) {
            if (hull[i].x == monsters[i % n].x && hull[i].y == monsters[i % n].y) {
                afraid.insert(i % n);
            }
        }
    }
    cout << afraid.size() << endl;
    return 0;
}