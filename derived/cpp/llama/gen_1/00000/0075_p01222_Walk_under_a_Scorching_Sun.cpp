#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-12;

struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
};

double cross(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double dot(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

bool intersect(const Line& l1, const Line& l2, Point& p) {
    double d = cross(l1.p2 - l1.p1, l2.p2 - l2.p1);
    if (fabs(d) < EPS) return false;
    p.x = (cross(l2.p2 - l2.p1, l2.p1 - l1.p1) / d + l1.p1.x);
    p.y = (cross(l2.p2 - l2.p1, l2.p1 - l1.p1) / d * (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x) + l1.p1.y);
    return true;
}

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double solve(const vector<Line>& buildings, const vector<Line>& roads, double theta, double phi, const Point& s, const Point& t) {
    Point sunDir = {cos(theta * PI / 180), sin(theta * PI / 180)};
    Point sunVec = {sunDir.x, sunDir.y, -1 / tan(phi * PI / 180)};
    double res = 0;
    for (const auto& road : roads) {
        Point shadeStart = road.p1, shadeEnd = road.p2;
        for (const auto& building : buildings) {
            for (int i = 0; i < building.p2.x - building.p1.x + 1; i++) {
                double x1 = building.p1.x + i;
                double y1 = building.p1.y;
                double x2 = building.p2.x + i;
                double y2 = building.p2.y;
                Line line = {{x1, y1}, {x2, y2}};
                Point p;
                if (intersect(line, road, p)) {
                    if (p.x > shadeStart.x) {
                        shadeStart = p;
                    } else {
                        shadeEnd = p;
                    }
                }
            }
        }
        if (shadeStart.x <= shadeEnd.x) {
            res += distance(shadeStart, shadeEnd);
        }
    }
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<Line> buildings(n), roads(m);
        vector<int> nv(n), h(n);
        for (int i = 0; i < n; i++) {
            cin >> nv[i] >> h[i];
            buildings[i].p1 = {0, 0};
            for (int j = 0; j < nv[i]; j++) {
                double x, y;
                cin >> x >> y;
                if (j == nv[i] - 1) {
                    buildings[i].p2 = {x, y};
                }
            }
        }
        for (int i = 0; i < m; i++) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            roads[i] = {{x1, y1}, {x2, y2}};
        }
        double theta, phi;
        cin >> theta >> phi;
        Point s, t;
        cin >> s.x >> s.y >> t.x >> t.y;
        cout << fixed << setprecision(3) << solve(buildings, roads, theta, phi, s, t) << endl;
    }
    return 0;
}