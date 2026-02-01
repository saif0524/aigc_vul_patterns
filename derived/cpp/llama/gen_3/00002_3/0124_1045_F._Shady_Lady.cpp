#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

bool cmp(const Point& a, const Point& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), cmp);

    bool hasZero = false;
    for (const auto& point : points) {
        if (point.x == 0 && point.y == 0) {
            hasZero = true;
            break;
        }
    }

    if (!hasZero) {
        cout << "Ani\n";
        return 0;
    }

    int count = 0;
    for (const auto& point : points) {
        if (point.x == 0 || point.y == 0) {
            ++count;
        }
    }

    if (count >= 3) {
        cout << "Borna\n";
        return 0;
    }

    if (count == 1) {
        cout << "Ani\n";
        return 0;
    }

    for (const auto& point : points) {
        if (point.x > 0 && point.y > 0) {
            cout << "Ani\n";
            return 0;
        }
    }

    cout << "Borna\n";
    return 0;
}