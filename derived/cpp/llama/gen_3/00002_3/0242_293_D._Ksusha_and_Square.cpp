#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

long long orientation(const Point& p, const Point& q, const Point& r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool onSegment(const Point& p, const Point& q, const Point& r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool doIntersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2) {
    long long o1 = orientation(p1, q1, p2);
    long long o2 = orientation(p1, q1, q2);
    long long o3 = orientation(p2, q2, p1);
    long long o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

bool isInside(const vector<Point>& polygon, const Point& p) {
    int n = polygon.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        const Point& q1 = polygon[i];
        const Point& q2 = polygon[j];

        if (((q1.y <= p.y && q2.y > p.y) || (q1.y > p.y && q2.y <= p.y)) &&
            (p.x < (q2.x - q1.x) * (p.y - q1.y) / (q2.y - q1.y) + q1.x))
            inside = !inside;
    }

    return inside;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (auto& p : polygon)
        cin >> p.x >> p.y;

    long long minX = LLONG_MAX, maxX = LLONG_MIN, minY = LLONG_MAX, maxY = LLONG_MIN;
    for (const auto& p : polygon) {
        minX = min(minX, p.x);
        maxX = max(maxX, p.x);
        minY = min(minY, p.y);
        maxY = max(maxY, p.y);
    }

    vector<Point> points;
    for (int x = minX; x <= maxX; ++x) {
        for (int y = minY; y <= maxY; ++y) {
            Point p = {x, y};
            if (isInside(polygon, p))
                points.push_back(p);
        }
    }

    long long totalPoints = points.size();
    long long totalArea = 0;

    for (int i = 0; i < totalPoints; ++i) {
        for (int j = i + 1; j < totalPoints; ++j) {
            long long dx = abs(points[i].x - points[j].x);
            long long dy = abs(points[i].y - points[j].y);
            totalArea += dx * dx + dy * dy;
        }
    }

    double expectedArea = (double)totalArea / (totalPoints * (totalPoints - 1) / 2);
    printf("%.10lf\n", expectedArea);

    return 0;
}