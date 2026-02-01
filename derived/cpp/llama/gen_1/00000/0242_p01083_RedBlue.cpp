#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n;
    cin >> n;

    Point c1, c2;
    cin >> c1.x >> c1.y >> c2.x >> c2.y >> c2.x >> c2.y;

    vector<Point> red(n), blue(n);
    for (int i = 0; i < n; i++) {
        cin >> red[i].x >> red[i].y;
    }
    for (int i = 0; i < n; i++) {
        cin >> blue[i].x >> blue[i].y;
    }

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    double ans = 1e18;
    do {
        bool ok = true;
        double cur = 0;
        for (int i = 0; i < n; i++) {
            int idx = perm[i];
            Point a = red[i], b = blue[idx];
            Point l = c1, r = c2;

            if (dist(a, l) < l.y - c2.y || dist(b, r) < r.y - c2.y) {
                ok = false;
                break;
            }

            double ang1 = atan2(a.y - l.y, a.x - l.x);
            double ang2 = atan2(b.y - r.y, b.x - r.x);

            double nx = min(a.x, b.x) + abs(a.x - b.x) / 2;
            double ny = min(a.y, b.y) + abs(a.y - b.y) / 2;

            cur += dist(a, {nx, ny}) + dist(b, {nx, ny});
        }

        if (ok) {
            ans = min(ans, cur);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    if (ans == 1e18) {
        cout << "Impossible" << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}