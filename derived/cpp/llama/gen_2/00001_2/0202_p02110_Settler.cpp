#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

struct Point {
    int x, y, index;
    Point(int x = 0, int y = 0, int index = 0) : x(x), y(y), index(index) {}
    bool operator<(const Point& other) const {
        return index < other.index;
    }
};

bool checkDistance(const Point& p1, const Point& p2) {
    int dx = abs(p1.x - p2.x);
    int dy = abs(p1.y - p2.y);
    return sqrt(dx * dx + dy * dy) >= 2.0;
}

bool checkPoints(const vector<Point>& points, int start, int end, int k) {
    if (end - start + 1 < k) return false;
    vector<bool> used(end - start + 1, false);
    vector<int> result;
    return checkPointsRecursive(points, start, end, k, used, result);
}

bool checkPointsRecursive(const vector<Point>& points, int start, int end, int k, vector<bool>& used, vector<int>& result) {
    if (k == 0) return true;
    for (int i = start; i <= end; ++i) {
        if (!used[i]) {
            bool canUse = true;
            for (const auto& p : result) {
                if (!checkDistance(points[p], points[i])) {
                    canUse = false;
                    break;
                }
            }
            if (canUse) {
                used[i] = true;
                result.push_back(i);
                if (checkPointsRecursive(points, i + 1, end, k - 1, used, result)) {
                    return true;
                }
                used[i] = false;
                result.pop_back();
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y, i + 1);
    }
    sort(points.begin(), points.end());

    vector<bool> used(n, false);
    vector<int> result;
    if (checkPoints(points, 0, n - 1, k)) {
        checkPointsRecursive(points, 0, n - 1, k, used, result);
        for (const auto& i : result) {
            cout << points[i].index << '\n';
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}