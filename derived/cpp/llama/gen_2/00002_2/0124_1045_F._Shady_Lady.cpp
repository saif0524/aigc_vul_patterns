#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool cmp(const Point& a, const Point& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), cmp);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, points[i].y);
    }
    if (mx == 0) {
        cout << "Borna" << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].y == mx) cnt++;
    }
    if (cnt > 1) {
        cout << "Borna" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (points[i].x == 0 && points[i].y == 0) {
            cout << "Borna" << endl;
            return 0;
        }
    }
    cout << "Ani" << endl;
    return 0;
}