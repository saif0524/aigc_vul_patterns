#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

struct Point {
    double x, y;
};

double cross(const Point& p, const Point& q, const Point& r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

double area(const vector<Point>& poly) {
    int n = poly.size();
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += cross(poly[0], poly[i], poly[j]);
    }
    return abs(area) / 2;
}

bool equal(const double& a, const double& b) {
    return abs(a - b) < EPS;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }
    double totalArea = area(poly);
    if (equal(totalArea, 0)) {
        cout << "NA" << endl;
        return;
    }
    double halfArea = totalArea / 2;
    double minX = poly[0].x, maxX = poly[0].x;
    double minY = poly[0].y, maxY = poly[0].y;
    for (int i = 1; i < n; i++) {
        minX = min(minX, poly[i].x);
        maxX = max(maxX, poly[i].x);
        minY = min(minY, poly[i].y);
        maxY = max(maxY, poly[i].y);
    }
    double x = (minX + maxX) / 2;
    double y = (minY + maxY) / 2;
    double step = 10000;
    while (step > EPS) {
        if (x + step < maxX) {
            vector<Point> leftPoly, rightPoly;
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                if (cross({x + step, y}, poly[i], poly[j]) >= 0) {
                    leftPoly.push_back(poly[i]);
                } else {
                    rightPoly.push_back(poly[i]);
                }
            }
            if (!leftPoly.empty() && !rightPoly.empty()) {
                double leftArea = area(leftPoly);
                double rightArea = area(rightPoly);
                if (abs(leftArea - rightArea) < EPS) {
                    x += step;
                    break;
                } else if (leftArea < rightArea) {
                    x += step;
                } else {
                    y += step;
                }
            }
        } else if (x - step > minX) {
            vector<Point> leftPoly, rightPoly;
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                if (cross({x - step, y}, poly[i], poly[j]) >= 0) {
                    leftPoly.push_back(poly[i]);
                } else {
                    rightPoly.push_back(poly[i]);
                }
            }
            if (!leftPoly.empty() && !rightPoly.empty()) {
                double leftArea = area(leftPoly);
                double rightArea = area(rightPoly);
                if (abs(leftArea - rightArea) < EPS) {
                    x -= step;
                    break;
                } else if (leftArea < rightArea) {
                    x -= step;
                } else {
                    y -= step;
                }
            }
        } else if (y + step < maxY) {
            vector<Point> leftPoly, rightPoly;
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                if (cross({x, y + step}, poly[i], poly[j]) >= 0) {
                    leftPoly.push_back(poly[i]);
                } else {
                    rightPoly.push_back(poly[i]);
                }
            }
            if (!leftPoly.empty() && !rightPoly.empty()) {
                double leftArea = area(leftPoly);
                double rightArea = area(rightPoly);
                if (abs(leftArea - rightArea) < EPS) {
                    y += step;
                    break;
                } else if (leftArea < rightArea) {
                    y += step;
                } else {
                    x -= step;
                }
            }
        } else if (y - step > minY) {
            vector<Point> leftPoly, rightPoly;
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                if (cross({x, y - step}, poly[i], poly[j]) >= 0) {
                    leftPoly.push_back(poly[i]);
                } else {
                    rightPoly.push_back(poly[i]);
                }
            }
            if (!leftPoly.empty() && !rightPoly.empty()) {
                double leftArea = area(leftPoly);
                double rightArea = area(rightPoly);
                if (abs(leftArea - rightArea) < EPS) {
                    y -= step;
                    break;
                } else if (leftArea < rightArea) {
                    y -= step;
                } else {
                    x += step;
                }
            }
        }
        step /= 2;
    }
    cout << fixed;
    cout.precision(5);
    cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}