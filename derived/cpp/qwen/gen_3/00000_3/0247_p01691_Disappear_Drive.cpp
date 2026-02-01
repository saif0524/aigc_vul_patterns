#include <bits/stdc++.h>
using namespace std;

typedef double db;

const db EPS = 1e-9;
const db INF = 1e18;
const int MAXN = 10;

struct Point {
    db x, y;
    Point() {}
    Point(db x, db y) : x(x), y(y) {}
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    db operator*(const Point& o) const { return x * o.x + y * o.y; }
    db operator%(const Point& o) const { return x * o.y - y * o.x; }
    db norm2() const { return (*this) * (*this); }
    db norm() const { return sqrt(norm2()); }
};

struct Circle {
    Point c;
    db r;
    Circle() {}
    Circle(Point c, db r) : c(c), r(r) {}
    bool inside(Point p) const { return (p - c).norm() < r - EPS; }
};

db dist(Point a, Point b) {
    return (a - b).norm();
}

db dist(Point a, Circle b) {
    db d = dist(a, b.c);
    if (d > b.r) return d - b.r;
    return 0;
}

db dist(Circle a, Circle b) {
    db d = dist(a.c, b.c);
    if (d > a.r + b.r) return d - a.r - b.r;
    return 0;
}

int n, D;
Point S(25, 0), G(25, 94);
vector<Circle> C(MAXN);
db dp[2][MAXN+1][6];

int sgnum(db x) {
    return x < -EPS ? -1 : (x > EPS ? 1 : 0);
}

bool check(Point p) {
    for (int i = 0; i < n; i++) {
        if (C[i].inside(p)) return false;
    }
    return true;
}

pair<int, Point> intersect(Circle a, Circle b) {
    db d = dist(a.c, b.c);
    db cos = (d * d + a.r * a.r - b.r * b.r) / (2 * d * a.r);
    db sin = sqrt(1 - cos * cos);
    db x1 = a.c.x + a.r * cos, y1 = a.c.y + a.r * sin;
    db x2 = a.c.x + a.r * cos, y2 = a.c.y - a.r * sin;
    if (dist(Point(x1, y1), b.c) < b.r + EPS) return {1, Point(x1, y1)};
    if (dist(Point(x2, y2), b.c) < b.r + EPS) return {1, Point(x2, y2)};
    return {0, Point()};
}

db sweep(int dir, int u, int d) {
    if (d < 0) return INF;
    db ans = INF;
    if (u == n) {
        if (d == D) ans = min(ans, dist(dir ? G : S, C[u-1].c) - C[u-1].r);
        return ans;
    }
    if (dp[dir][u][d] + EPS < INF) return dp[dir][u][d];
    ans = sweep(dir, u + 1, d);
    if (u == 0) {
        if (dir == 0) ans = min(ans, dist(S, C[u].c) - C[u].r);
        else ans = min(ans, dist(G, C[u].c) - C[u].r);
    } else {
        pair<int, Point> inter = intersect(C[u-1], C[u]);
        if (inter.first) {
            if (u == n - 1 && dir == 1) {
                ans = min(ans, dist(C[u-1].c, inter.second) - C[u-1].r + dist(inter.second, G) - C[u].r);
            } else if (u == n - 1 && dir == 0) {
                ans = min(ans, dist(S, inter.second) - C[u].r);
            } else if (check(inter.second) && dist(C[u-1].c, inter.second) > C[u-1].r + EPS && dist(C[u].c, inter.second) > C[u].r + EPS) {
                db old = dist(C[u-1].c, inter.second) - C[u-1].r;
                db now = dist(C[u].c, inter.second) - C[u].r;
                ans = min(ans, old + sweep(dir, u + 1, d - 1) + now);
            }
        }
    }
    dp[dir][u][d] = ans;
    return ans;
}

int main(){
    cin >> n >> D;
    for(int i=0;i<n;i++) cin >> C[i].c.x >> C[i].c.y >> C[i].r;
    memset(dp, 0x3f, sizeof(dp));
    db ans = min(sweep(0, 0, D), dist(S, G));
    if(ans + EPS > INF / 2) ans = -1;
    printf("%.10f\n", ans);
}