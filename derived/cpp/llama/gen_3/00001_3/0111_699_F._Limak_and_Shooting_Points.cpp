#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

long long cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(const Point& a, const Point& b, const Point& c) {
    return cross(a, b, c) > 0;
}

bool ccw(const Point& a, const Point& b, const Point& c) {
    return cross(a, b, c) < 0;
}

bool collinear(const Point& a, const Point& b, const Point& c) {
    return cross(a, b, c) == 0;
}

bool convexHull(vector<Point>& points) {
    if (points.size() < 3) return false;
    sort(points.begin(), points.end(), cmp);
    vector<Point> hull;
    for (int i = 0; i < points.size(); i++) {
        while (hull.size() >= 2 && cw(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    int t = hull.size();
    for (int i = points.size() - 2; i >= 0; i--) {
        while (hull.size() >= t + 1 && cw(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    points = hull;
    return true;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<Point> stones(k);
    for (int i = 0; i < k; i++) {
        cin >> stones[i].x >> stones[i].y;
    }
    vector<Point> monsters(n);
    for (int i = 0; i < n; i++) {
        cin >> monsters[i].x >> monsters[i].y;
    }
    vector<Point> points;
    for (int i = 0; i < k; i++) {
        points.push_back(stones[i]);
    }
    for (int i = 0; i < n; i++) {
        points.push_back(monsters[i]);
    }
    convexHull(points);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < points.size(); j++) {
            if (points[j].x == monsters[i].x && points[j].y == monsters[i].y) {
                found = true;
                break;
            }
        }
        if (found) ans++;
    }
    cout << ans << endl;
    return 0;
}