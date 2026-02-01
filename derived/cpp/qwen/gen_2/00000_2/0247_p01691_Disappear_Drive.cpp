#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5;
const double INF = 1e18;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
    Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
    Point operator*(double d) const { return Point(x * d, y * d); }
    double norm() const { return x * x + y * y; }
    double length() const { return sqrt(norm()); }
};

double dist(const Point& a, const Point& b) { return (a - b).length(); }

bool insideCircle(const Point& p, const pair<Point, double>& circle) {
    return dist(p, circle.first) < circle.second;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<pair<Point, double>> circles(N);
    for (auto& circle : circles) {
        cin >> circle.first.x >> circle.first.y >> circle.second;
    }

    Point S(25, 0), G(25, 94);

    vector<vector<double>> dp(1 << N, vector<double>(D + 1, INF));
    dp[0][0] = dist(S, G);

    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int d = 0; d <= D; ++d) {
            if (dp[mask][d] == INF) continue;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) continue;

                Point center = circles[i].first;
                double radius = circles[i].second;

                double minDist = dp[mask][d];
                for (int j = 0; j < N; ++j) {
                    if (i == j || !(mask & (1 << j))) continue;
                    Point center2 = circles[j].first;
                    double radius2 = circles[j].second;
                    double distCC = dist(center, center2);
                    double t = (radius + radius2) / distCC;
                    Point p = center + (center2 - center) * t;
                    if (insideCircle(p, circles[i]) && insideCircle(p, circles[j])) {
                        minDist = min(minDist, dp[mask | (1 << j)][d]);
                    }
                }

                for (int j = 0; j < N; ++j) {
                    if (mask & (1 << j)) continue;
                    Point center2 = circles[j].first;
                    double radius2 = circles[j].second;
                    double distCC = dist(center, center2);
                    double t = (radius + radius2) / distCC;
                    Point p = center + (center2 - center) * t;
                    if (insideCircle(p, circles[i]) && insideCircle(p, circles[j])) {
                        minDist = min(minDist, dp[mask | (1 << j)][d]);
                    }
                }

                for (int j = 0; j < N; ++j) {
                    if (mask & (1 << j)) continue;
                    Point center2 = circles[j].first;
                    double radius2 = circles[j].second;
                    double distCC = dist(center, center2);
                    double t = (radius + radius2) / distCC;
                    Point p = center + (center2 - center) * t;
                    if (insideCircle(p, circles[i]) && insideCircle(p, circles[j])) {
                        minDist = min(minDist, dp[mask | (1 << j)][d]);
                    }
                }

                if (d < D) {
                    Point P(25, 0);
                    for (double theta = 0; theta < 2 * M_PI; theta += M_PI / 180) {
                        P.x = center.x + radius * cos(theta);
                        P.y = center.y + radius * sin(theta);
                        double newDist = dp[mask][d] - dist(S, center) + dist(S, P) + dist(P, G);
                        dp[mask | (1 << i)][d + 1] = min(dp[mask | (1 << i)][d + 1], newDist);
                    }
                }

                dp[mask | (1 << i)][d] = minDist;
            }
        }
    }

    double ans = INF;
    for (int d = 0; d <= D; ++d) {
        ans = min(ans, dp[(1 << N) - 1][d]);
    }

    if (ans == INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}