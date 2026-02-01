#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& p : points) {
        cin >> p.x >> p.y;
    }

    vector<Point> result;
    result.insert(result.end(), points.begin(), points.end());

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            Point p;
            p.x = points[i].x;
            p.y = points[j].y;
            result.push_back(p);
        }
    }

    cout << result.size() << endl;
    for (const auto& p : result) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}