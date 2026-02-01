#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y;
};

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(const Point &o, const Point &a, const Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool convexHull(vector<Point> &p) {
    int n = p.size();
    if (n < 3) return false;
    sort(p.begin(), p.end(), cmp);
    vector<Point> h(2 * n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        while (s > 1 && cross(h[s - 2], h[s - 1], p[i]) <= 0) --s;
        h[s++] = p[i];
    }
    int m = s + 1;
    for (int i = n - 2; i >= 0; --i) {
        while (s > m && cross(h[s - 2], h[s - 1], p[i]) <= 0) --s;
        h[s++] = p[i];
    }
    p.clear();
    for (int i = 0; i < s - 1; ++i) p.push_back(h[i]);
    return p.size() > 2;
}

double angle(const Point &a, const Point &b, const Point &c) {
    return atan2(b.y - a.y, b.x - a.x) - atan2(c.y - a.y, c.x - a.x);
}

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    if (!convexHull(p)) return;
    int tg, tw;
    cin >> tg >> tw;
    Point s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    double ans = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        Point a = p[i];
        Point b = p[(i + 1) % n];
        if (cross(a, b, t) <= 0 && cross(a, b, s) <= 0) {
            double A = b.x - a.x;
            double B = b.y - a.y;
            double C = a.x * a.y - b.x * b.y;
            double d = abs(A * t.y - A * t.x + B * t.x - B * t.y + C) / sqrt(A * A + B * B);
            if (d < EPS) {
                double len = min(dist(s, a), dist(s, b)) / tg + dist({(a.x + b.x) / 2, (a.y + b.y) / 2}, t) / tw;
                ans = min(ans, len);
            } else {
                double len1 = dist(s, a) / tg + dist(a, t) / tw;
                double len2 = dist(s, b) / tg + dist(b, t) / tw;
                ans = min(ans, len1);
                ans = min(ans, len2);
            }
        }
    }
    cout << fixed;
    cout.precision(8);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve();
    }
    return 0;
}