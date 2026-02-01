#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
#define X real()
#define Y imag()
#define EPS 1e-9
double DEG_to_RAD(double d) { return d*M_PI/180.0; }

double dist(point p1, point p2) {
    return abs(p1-p2);
}

point rotate(point p, double theta) {
    return point(p.X*cos(theta) - p.Y*sin(theta), p.X*sin(theta) + p.Y*cos(theta));
}

bool inCircle(point p, point c, double r) {
    return dist(p, c) <= r + EPS;
}

pair<point, double> circumcircle(point p1, point p2, point p3) {
    double d = 2.0 * (p1.X * (p2.Y - p3.Y) + p2.X * (p3.Y - p1.Y) + p3.X * (p1.Y - p2.Y));
    double ux = ((p1.X*p1.X + p1.Y*p1.Y) * (p2.Y - p3.Y) + (p2.X*p2.X + p2.Y*p2.Y) * (p3.Y - p1.Y) + (p3.X*p3.X + p3.Y*p3.Y) * (p1.Y - p2.Y)) / d;
    double uy = ((p1.X*p1.X + p1.Y*p1.Y) * (p3.X - p2.X) + (p2.X*p2.X + p2.Y*p2.Y) * (p1.X - p3.X) + (p3.X*p3.X + p3.Y*p3.Y) * (p2.X - p1.X)) / d;
    double r = dist(point(ux, uy), p1);
    return { point(ux, uy), r };
}

pair<point, double> enclosingCircle(vector<point>& points) {
    random_shuffle(points.begin(), points.end());
    point c(points[0]); double r = 0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        if (dist(points[i], c) > r + EPS) {
            c = points[i], r = 0;
            for (int j = 0; j < i; ++j) {
                if (dist(points[j], c) > r + EPS) {
                    c = (points[i] + points[j]) / 2;
                    r = dist(points[i], c);
                    for (int k = 0; k < j; ++k) {
                        if (dist(points[k], c) > r + EPS) {
                            c = circumcircle(points[i], points[j], points[k]).first;
                            r = circumcircle(points[i], points[j], points[k]).second;
                        }
                    }
                }
            }
        }
    }
    return { c, r };
}

double angleBetween(point a, point b) {
    double dot = a.X * b.X + a.Y * b.Y;
    double det = a.X * b.Y - a.Y * b.X;
    return atan2(det, dot);
}

bool inMagicCircle(point p, int M, int K) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (gcd(i, M) == 1 && (j - i + M) % M == (K * gcd(i, M)) % M) {
                point dir1(cos(2 * M_PI * i / M), sin(2 * M_PI * i / M));
                point dir2(cos(2 * M_PI * j / M), sin(2 * M_PI * j / M));
                double ang1 = angleBetween(dir1, p);
                double ang2 = angleBetween(dir2, p);
                if (fabs(ang1) <= EPS || fabs(ang2) <= EPS || fabs(ang1 - ang2) <= EPS) return true;
                if (fabs(ang1 - ang2) >= M_PI - EPS) return true;
            }
        }
    }
    return false;
}

double solve(vector<point>& points, int M, int K) {
    pair<point, double> enclosing = enclosingCircle(points);
    double lo = 0, hi = 2000;
    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2;
        bool covered = true;
        for (auto& p : points) {
            point p2 = p - enclosing.first;
            point p3 = rotate(p2, M_PI / 2) * (mid / abs(p2)) + enclosing.first;
            if (!inMagicCircle(p3 - enclosing.first, M, K)) {
                covered = false;
                break;
            }
        }
        if (covered) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    while(cin >> N >> M >> K, N || M || K){
        vector<point> points(N);
        for(int i = 0; i < N; ++i){
            cin >> points[i].X >> points[i].Y;
        }
        cout << solve(points, M, K) << "\n";
    }
}