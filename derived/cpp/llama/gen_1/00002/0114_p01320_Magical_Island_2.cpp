#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<double, double> pdd;

const int MAXN = 60;

int n, m, k;
pdd points[MAXN];

double eps = 1e-10;
double pi = acos(-1.0);

double euclideanDistance(pdd p1, pdd p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double computeDistance(pdd p) {
    for (int i = 0; i < n; i++) {
        if (euclideanDistance(p, points[i]) > eps * n) {
            return 1e10;
        }
    }
    return 0;
}

double angleBetweenPoints(pdd p1, pdd p2) {
    double dx = p2.first - p1.first;
    double dy = p2.second - p1.second;
    if (dy < 0) {
        return 2 * pi - atan2(-dy, -dx);
    } else {
        return atan2(dy, dx);
    }
}

bool isPointInside(pdd center, double radius, pdd point) {
    double angle = angleBetweenPoints(center, point);
    double angles[MAXN];
    for (int i = 0; i < k; i++) {
        angles[i] = pi * 2 * i / m;
    }
    for (int i = 0; i < k; i++) {
        if (angle <= angles[i] + pi / m && angle >= angles[i] - pi / m) {
            return true;
        }
    }
    return false;
}

bool isSettled(pdd center, double radius) {
    for (int i = 0; i < n; i++) {
        if (!isPointInside(center, radius, points[i])) {
            return false;
        }
    }
    return true;
}

double solve() {
    double angle = 0;
    double step = pi / 1000.0;
    while (angle < 2 * pi) {
        pdd p(1000 * cos(angle), 1000 * sin(angle));
        double left = 0, right = 1e10;
        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2.0;
            if (isSettled(p, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        double answer = right;
        angle += step;
        for (int i = 0; i < 100; i++) {
            pdd nextP(1000 * cos(angle + step * i), 1000 * sin(angle + step * i));
            double left = 0, right = 1e10;
            for (int j = 0; j < 100; j++) {
                double mid = (left + right) / 2.0;
                if (isSettled(nextP, mid)) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            answer = min(answer, right);
        }
        angle += step * 100;
    }
    return answer;
}

int main() {
    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        cout << fixed;
        cout.precision(9);
        cout << solve() << endl;
    }
    return 0;
}