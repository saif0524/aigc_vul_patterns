#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), comparePoints);

    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        dp[i] = 1e9;
        for (int j = 0; j < i; j++) {
            int cost = dp[j] + abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
            dp[i] = min(dp[i], cost);
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}