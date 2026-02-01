#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool operator<(const Point& a, const Point& b) {
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
    sort(points.begin(), points.end());
    vector<Point> result = points;
    for (int i = 0; i < n - 1; i++) {
        result.push_back({points[i].x, points[i + 1].y});
    }
    cout << result.size() << endl;
    for (const auto& p : result) {
        cout << p.x << " " << p.y << endl;
    }
    return 0;
}