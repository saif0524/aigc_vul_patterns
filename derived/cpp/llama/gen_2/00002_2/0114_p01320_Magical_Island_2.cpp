#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double angle(double x, double y) {
    if (x == 0) {
        if (y > 0) return 0;
        else if (y < 0) return PI;
        else return 0;
    }
    double a = atan2(y, x);
    if (a < 0) a += 2 * PI;
    return a;
}

int main() {
    int N, M, K;
    while (cin >> N >> M >> K) {
        if (N == 0 && M == 0 && K == 0) break;
        vector<pair<double, double>> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].first >> points[i].second;
        }
        double ans = 1e9;
        for (int i = 0; i < 360; i++) {
            double rad = i * PI / 180;
            double maxR = 0;
            for (int j = 0; j < N; j++) {
                double x = points[j].first, y = points[j].second;
                double a = angle(x, y) - rad;
                if (a < 0) a += 2 * PI;
                double r = dist(0, 0, x, y);
                double d = fmod(a, 2 * PI / M);
                if (d > PI / M) d = 2 * PI / M - d;
                double k = K * 2 * PI / M;
                if (d > k / 2) {
                    r = max(r, dist(0, 0, r * cos(a - k / 2), r * sin(a - k / 2)));
                }
                maxR = max(maxR, r);
            }
            ans = min(ans, maxR);
        }
        printf("%.10f\n", ans);
    }
    return 0;
}