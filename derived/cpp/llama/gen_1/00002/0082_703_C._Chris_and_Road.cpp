#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

struct Point {
    double x, y;
};

bool intersect(Point p1, Point p2, Point q1, Point q2, double& x) {
    x = (q1.x * q2.y - q2.x * q1.y - p1.x * q2.y + p2.x * q1.y +
         p2.x * p1.y - p1.x * p2.y) / (q2.y - q1.y - p2.y + p1.y);
    return (min(q1.x, q2.x) <= x && x <= max(q1.x, q2.x) &&
            min(p1.y, p2.y) <= p1.x * (q2.y - q1.y) / (q1.x - q2.x) + q1.y - q1.x * (q2.y - q1.y) / (q1.x - q2.x) + x &&
            p1.x * (q2.y - q1.y) / (q1.x - q2.x) + q1.y - q1.x * (q2.y - q1.y) / (q1.x - q2.x) + x <= max(p1.y, p2.y));
}

int main() {
    int n, w;
    double v, u;
    scanf("%d%d%lf%lf", &n, &w, &v, &u);
    vector<Point> p(n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    double top = 0, bot = w;
    double ans = w / u;
    vector<double> cy(n);
    vector<double> ty(n);
    for (int i = 0; i < n; ++i) {
        cy[i] = p[i].y;
        if (i != n - 1)
            ty[i] = (p[i + 1].x - p[i].x) * (-u) / v + p[i].y;
        else
            ty[i] = (p[0].x - p[i].x) * (-u) / v + p[i].y;
    }
    double lo = 0, hi = ans + 1;
    for (int it = 0; it < 400; ++it) {
        double mid = (lo + hi) / 2;
        vector<double> ly(n);
        for (int i = 0; i < n; ++i) {
            ly[i] = ty[i] + v * mid;
        }
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            if (p[i].x + v * mid <= 0) continue;
            if (ly[i] >= min(cy[i], cy[(i + 1) % n]) &&
                ly[i] <= max(cy[i], cy[(i + 1) % n])) {
                ok = 0;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            double intersection;
            if (intersect({0, 0}, {0, w}, p[i], p[(i + 1) % n], intersection)) {
                if (intersection <= p[i].x + v * mid) {
                    double y = p[i].y + ((p[(i + 1) % n].y - p[i].y) * (intersection - p[i].x)) / (p[(i + 1) % n].x - p[i].x);
                    if (y >= top && y <= bot) {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%0.9f\n", ans);
    return 0;
}