#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const double INF = numeric_limits<double>::max();

struct Point {
    double x, y;
};

struct Star {
    Point center;
    double angle, radius;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double angleBetween(const Point& p1, const Point& p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

bool isInside(const Star& s1, const Star& s2) {
    double d = distance(s1.center, s2.center);
    return d + s2.radius <= s1.radius;
}

bool isIntersecting(const Star& s1, const Star& s2) {
    double d = distance(s1.center, s2.center);
    return d <= s1.radius + s2.radius;
}

double getDistance(const Star& s1, const Star& s2) {
    double d = distance(s1.center, s2.center);
    return d - s1.radius - s2.radius;
}

int main() {
    int n, m, l;
    while (cin >> n >> m >> l) {
        if (n == 0 && m == 0 && l == 0) break;

        vector<Star> stars(n);
        for (int i = 0; i < n; ++i) {
            cin >> stars[i].center.x >> stars[i].center.y >> stars[i].angle >> stars[i].radius;
        }

        vector<vector<double>> dist(n, vector<double>(n, INF));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i!= j) {
                    if (isInside(stars[i], stars[j])) {
                        dist[i][j] = 0.0;
                    } else if (isIntersecting(stars[i], stars[j])) {
                        dist[i][j] = 0.0;
                    } else {
                        dist[i][j] = getDistance(stars[i], stars[j]);
                    }
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        cout << fixed;
        cout.precision(17);
        cout << dist[m - 1][l - 1] << endl;
    }

    return 0;
}