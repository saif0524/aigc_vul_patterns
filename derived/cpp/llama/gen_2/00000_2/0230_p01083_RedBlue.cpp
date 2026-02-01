#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

const ld EPS = 1e-9;

struct Point {
    ld x, y;
    Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    ld operator*(const Point& p) const { return x * p.x + y * p.y; }  // dot product
    ld operator%(const Point& p) const { return x * p.y - y * p.x; }  // cross product
    ld len() const { return sqrt(x * x + y * y); }
    ld len2() const { return x * x + y * y; }
    ld dist(const Point& p) const { return (*this - p).len(); }
};

struct Circle {
    Point c;
    ld r;
    Circle(Point c, ld r) : c(c), r(r) {}
};

ld ccldist(const Circle& c1, const Circle& c2, const Point& p1, const Point& p2) {
    ld d = c1.c.dist(c2.c);
    if (d <= c1.r + c2.r + EPS || d >= abs(c1.r - c2.r) - EPS) {
        return p1.dist(p2);
    } else {
        ld ang1 = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
        ld ang2 = acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));
        Point v = (c2.c - c1.c) / d;
        Point u1 = Point(-v.y, v.x);
        Point u2 = Point(v.y, -v.x);
        Point np1 = c1.c + u1 * c1.r;
        Point np2 = c2.c + u2 * c2.r;
        return p1.dist(np1) + np1.dist(np2) + np2.dist(p2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Circle c1;
    cin >> c1.c.x >> c1.c.y >> c1.r;

    Circle c2;
    cin >> c2.c.x >> c2.c.y >> c2.r;

    vector<Point> red(n), blue(n);
    for (int i = 0; i < n; i++) {
        cin >> red[i].x >> red[i].y;
    }
    for (int i = 0; i < n; i++) {
        cin >> blue[i].x >> blue[i].y;
    }

    vector<ld> dist(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i * n + j] = ccldist(c1, c2, red[i], blue[j]);
        }
    }

    vector<vector<ld>> dp(1 << n, vector<ld>(n, 1e18));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] >= 1e18) continue;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) continue;
                dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[i * n + j]);
            }
        }
    }

    ld ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    if (ans >= 1e18) {
        cout << "Impossible" << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}