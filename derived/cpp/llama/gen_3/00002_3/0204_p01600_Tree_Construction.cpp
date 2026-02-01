#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y > rhs.y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto &p : points) {
        cin >> p.x >> p.y;
    }

    sort(points.begin(), points.end());

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            if (dx >= 0 && dy <= 0) {
                dp[i] = min(dp[i], dp[j] + dx - dy);
            }
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}