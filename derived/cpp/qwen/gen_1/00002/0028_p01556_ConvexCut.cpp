#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> pd;

const double EPS = 1e-9;

bool eq(double a, double b) {
    return fabs(a - b) < EPS;
}

double area(int n, vector<pd> &points) {
    double ret = 0.0;
    for (int i = 1; i < n - 1; ++i) {
        pd a = points[0], b = points[i], c = points[i + 1];
        ret += (a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) / 2.0;
    }
    return fabs(ret);
}

bool check(pd p, int n, vector<pd> &points, double target) {
    vector<pd> up, down;
    for (pd q : points) {
        double det = (q.first - p.first) * (points[0].second - p.second) - (q.second - p.second) * (points[0].first - p.first);
        if (eq(det, 0)) {
            up.push_back(q);
            down.push_back(q);
        } else if (det > 0) {
            up.push_back(q);
        } else {
            down.push_back(q);
        }
    }
    if (up.size() < 3 || down.size() < 3) return false;
    return eq(area(up.size(), up), target) && eq(area(down.size(), down), target);
}

int main() {
    int n;
    cin >> n;
    vector<pd> points(n);
    for (auto &p : points) cin >> p.first >> p.second;

    double total_area = area(n, points);
    if (fmod(total_area, 2.0) != 0.0) {
        cout << "NA\n";
        return 0;
    }
    double target = total_area / 2.0;

    double minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
    for (pd p : points) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    const double STEP = 0.0001;
    for (double x = minX; x <= maxX; x += STEP) {
        for (double y = minY; y <= maxY; y += STEP) {
            pd p(x, y);
            if (check(p, n, points, target)) {
                printf("%.5f %.5f\n", x, y);
                return 0;
            }
        }
    }
    cout << "NA\n";
    return 0;
}