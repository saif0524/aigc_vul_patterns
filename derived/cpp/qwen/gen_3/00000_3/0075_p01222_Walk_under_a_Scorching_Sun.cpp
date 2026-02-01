#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<db, db> pdd;

const db eps = 1e-9;
const db pi = acos(-1.0);

struct Point {
    db x, y;
    Point() : x(0), y(0) {}
    Point(db x, db y) : x(x), y(y) {}
    Point operator + (const Point& rhs) const { return Point(x + rhs.x, y + rhs.y); }
    Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
    Point operator * (const db& rhs) const { return Point(x * rhs, y * rhs); }
    Point operator / (const db& rhs) const { return Point(x / rhs, y / rhs); }
    db operator ^ (const Point& rhs) const { return x * rhs.y - y * rhs.x; } // cross product
    db operator * (const Point& rhs) const { return x * rhs.x + y * rhs.y; } // dot product
    db len() const { return sqrt(*this * *this); }
    Point unit() const { return *this / len(); }
    Point perp() const { return Point(-y, x); }
    Point rotate(db ang) const {
        db c = cos(ang), s = sin(ang);
        return Point(x * c - y * s, x * s + y * c);
    }
};

struct Line {
    Point a, b;
    Line() {}
    Line(Point a, Point b) : a(a), b(b) {}
    db dist(Point p) const {
        return fabs((p - a) ^ (b - a)) / (b - a).len();
    }
    Point proj(Point p) const {
        return a + (b - a).unit() * ((p - a) * (b - a)) / (b - a).len();
    }
    bool onseg(Point p) const {
        return fabs((p - a) ^ (b - a)) < eps && ((p - a) * (p - b)) <= eps;
    }
    Point inter(Line l) const {
        db s1 = (l.b - l.a) ^ (a - l.a), s2 = (l.b - l.a) ^ (b - l.a);
        return Point((a.x * s2 - b.x * s1) / (s2 - s1), (a.y * s2 - b.y * s1) / (s2 - s1));
    }
};

struct Polygon {
    vector<Point> pts;
    bool contains(Point p) const {
        int n = pts.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            if (pts[i].onseg(p)) return true;
            int k = (pts[j] - pts[i]) ^ (p - pts[i]);
            if (k > 0 && pts[i].y <= p.y && pts[j].y > p.y) ++cnt;
            if (k < 0 && pts[j].y <= p.y && pts[i].y > p.y) --cnt;
        }
        return cnt != 0;
    }
    Polygon proj(Line l, db h) {
        Polygon res;
        int n = pts.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            Point a = pts[i], b = pts[j];
            db d1 = l.dist(a) / cos(atan2((a - l.a) ^ (l.b - l.a), (a - l.a) * (l.b - l.a)));
            db d2 = l.dist(b) / cos(atan2((b - l.a) ^ (l.b - l.a), (b - l.a) * (l.b - l.a)));
            if (d1 < h && d2 < h) {
                res.pts.push_back(b);
            } else if (d1 < h && d2 >= h) {
                res.pts.push_back(l.inter(Line(a, a + (b - a).unit() * h)));
                res.pts.push_back(b);
            } else if (d1 >= h && d2 < h) {
                res.pts.push_back(l.inter(Line(a, a + (b - a).unit() * h)));
            }
        }
        return res;
    }
};

db to_rad(db deg) {
    return deg * pi / 180.0;
}

db calc_sunshine(vector<Line>& roads, vector<Polygon>& buildings, Line sunlight, db h, Point src, Point dst) {
    int n = roads.size();
    vector<vector<db>> g(n + 1, vector<db>(n + 1, 1e18));
    for (int i = 0; i < n; ++i) {
        g[i][i] = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (i == j - 1) {
                g[i][j] = (roads[i].b - roads[i].a).len();
                g[j][i] = g[i][j];
            } else {
                Point mid1 = roads[i].proj(src);
                Point mid2 = roads[j - 1].proj(dst);
                bool valid = true;
                for (auto& poly : buildings) {
                    if (poly.contains(mid1) || poly.contains(mid2)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    g[i][j] = (mid2 - mid1).len();
                    g[j][i] = g[i][j];
                }
            }
        }
    }
    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    db res = 1e18;
    for (int i = 0; i < n; ++i) {
        if (roads[i].onseg(src)) {
            for (int j = 0; j < n; ++j) {
                if (roads[j].onseg(dst)) {
                    res = min(res, g[i][j]);
                }
            }
        }
    }
    return res;
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<Polygon> buildings(n);
        for (int i = 0; i < n; ++i) {
            int nv, h;
            cin >> nv >> h;
            buildings[i].pts.resize(nv);
            for (int j = 0; j < nv; ++j) {
                cin >> buildings[i].pts[j].x >> buildings[i].pts[j].y;
            }
        }
        vector<Line> roads(m);
        for (int i = 0; i < m; ++i) {
            cin >> roads[i].a.x >> roads[i].a.y >> roads[i].b.x >> roads[i].b.y;
        }
        db theta, phi;
        cin >> theta >> phi;
        Point src, dst;
        cin >> src.x >> src.y >> dst.x >> dst.y;
        theta = to_rad(theta);
        phi = to_rad(phi);
        db h = 1 / tan(phi);
        Point sun_dir(sin(theta), cos(theta)), sun_perp(cos(theta), -sin(theta));
        Line sunlight(src, src + sun_dir.rotate(-phi));
        for (auto& poly : buildings) {
            poly = poly.proj(sunlight, h);
        }
        cout << fixed << setprecision(10) << calc_sunshine(roads, buildings, sunlight, h, src, dst) << '\n';
    }
}