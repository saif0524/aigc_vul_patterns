#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

int main() {
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    int n;
    scanf("%d", &n);
    vector<double> a(n), w(n), x(n), y(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf %lf %lf", &x[i], &y[i], &a[i], &w[i]);
    }
    int k;
    scanf("%d", &k);

    auto calc = [&](double v) {
        vector<double> t(n);
        for (int i = 0; i < n; ++i) {
            double dx = x[i] - x1;
            double dy = y[i] - y1;
            double ang = atan2(dy, dx);
            double d = sqrt(dx * dx + dy * dy);
            double t0 = (ang - a[i]) / w[i];
            if (t0 < 0) t0 = -t0;
            t[i] = (a[i] + w[i] * t0 - ang) / (w[i] + EPS);
            t[i] = max(t[i], (a[i] + w[i] * t0 - ang + 2 * PI) / (w[i] + EPS));
            t[i] = max(t[i], (a[i] + w[i] * t0 - ang - 2 * PI) / (w[i] + EPS));
            double vx = v * (x2 - x1) / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            double vy = v * (y2 - y1) / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            dx = x[i] - x1 - vx * t[i];
            dy = y[i] - y1 - vy * t[i];
            double d0 = sqrt(dx * dx + dy * dy);
            double alpha = acos((d * d + d0 * d0 - v * v * t[i] * t[i]) / (2 * d * d0));
            if (abs(d0 - v * t[i]) < EPS) alpha = 0;
            if (abs(alpha - PI / 2) < EPS) t[i] = d / v;
            else t[i] = (d * cos(alpha)) / v;
        }
        sort(t.begin(), t.end());
        return t[k];
    };

    double l = 0, r = 1e9;
    while (r - l > EPS) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (calc(m1) > calc(m2)) l = m1;
        else r = m2;
    }
    printf("%.5lf\n", l);

    return 0;
}