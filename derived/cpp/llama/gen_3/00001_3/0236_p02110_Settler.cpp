#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, index;
};

bool comparePoints(const Point& a, const Point& b) {
    return a.index < b.index;
}

bool isFarEnough(const Point& a, const Point& b) {
    double distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return distance >= 2;
}

bool isValidCombination(const vector<Point>& combination) {
    for (int i = 0; i < combination.size(); i++) {
        for (int j = i + 1; j < combination.size(); j++) {
            if (!isFarEnough(combination[i], combination[j])) {
                return false;
            }
        }
    }
    return true;
}

void solve(vector<Point>& points, int k, int start, vector<Point>& current, vector<Point>& result) {
    if (current.size() == k) {
        if (isValidCombination(current)) {
            if (result.empty() || current < result) {
                result = current;
            }
        }
        return;
    }

    for (int i = start; i < points.size(); i++) {
        current.push_back(points[i]);
        solve(points, k, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
    }

    sort(points.begin(), points.end(), comparePoints);

    vector<Point> result;
    vector<Point> current;
    solve(points, k, 0, current, result);

    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto& point : result) {
            cout << point.index << endl;
        }
    }

    return 0;
}