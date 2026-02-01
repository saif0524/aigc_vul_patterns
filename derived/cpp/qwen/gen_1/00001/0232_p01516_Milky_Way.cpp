#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point rotate(double a) const {
        return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    double dist(const Point& p) const {
        return hypot(x - p.x, y - p.y);
    }
};

vector<Point> star_vertices(Point c, double angle, double r, int n = 5) {
    vector<Point> vertices;
    double base_angle = PI / 2 - angle / 180 * PI;
    for (int i = 0; i < n; ++i) {
        vertices.push_back(c + Point(r, 0).rotate(base_angle + i * 2 * PI / n));
    }
    return vertices;
}

bool is_inside(const Point& p, const vector<Point>& vertices) {
    int n = vertices.size();
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        double a = atan2(vertices[j].y - p.y, vertices[j].x - p.x) - atan2(vertices[i].y - p.y, vertices[i].x - p.x);
        if (a > PI) a -= 2 * PI;
        if (a < -PI) a += 2 * PI;
        sum += a;
    }
    return fabs(sum) > PI / 2;
}

double ccw(const Point& a, const Point& b, const Point& c) {
    return (b - a).x * (c - a).y - (b - a).y * (c - a).x;
}

bool intersect_segment(const Point& a, const Point& b, const Point& c, const Point& d) {
    return ccw(a, c, d) * ccw(b, c, d) < EPS && ccw(c, a, b) * ccw(d, a, b) < EPS;
}

double convex_distance(const vector<Point>& poly1, const vector<Point>& poly2) {
    double min_dist = 1e18;
    for (const auto& p : poly1) {
        if (!is_inside(p, poly2)) {
            for (const auto& q : poly2) {
                min_dist = min(min_dist, p.dist(q));
            }
        }
    }
    int n = poly1.size(), m = poly2.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (intersect_segment(poly1[i], poly1[(i + 1) % n], poly2[j], poly2[(j + 1) % m])) {
                return 0;
            }
        }
    }
    return min_dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, L;
    while(cin >> N >> M >> L && (N || M || L)){
        vector<vector<Point>> stars(N);
        for(int i = 0; i < N; ++i){
            double x, y, a, r;
            cin >> x >> y >> a >> r;
            stars[i] = star_vertices(Point(x, y), a, r);
        }
        vector<vector<double>> dp(N, vector<double>(N, 1e18));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i == j) continue;
                dp[i][j] = convex_distance(stars[i], stars[j]);
            }
        }
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        cout << fixed << setprecision(20) << dp[M-1][L-1] << "\n";
    }
}