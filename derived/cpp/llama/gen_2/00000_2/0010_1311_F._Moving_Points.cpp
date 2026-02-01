#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, v, id;

    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x;
        points[i].id = i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> points[i].v;
    }

    sort(points.begin(), points.end());

    long long total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = iivic + 1; j < n; ++j) {
            long long dx = points[j].x - points[i].x;
            long long dv = points[j].v - points[i].v;

            if (dv == 0) {
                total += dx;
            } else {
                long long t = dx / dv;
                if (t * dv * dv > dx * dx) {
                    total += abs(dx);
                } else {
                    total += abs(dx - t * dv);
                }
            }
        }
    }

    cout << total << '\n';

    return 0;
}