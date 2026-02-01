#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 16;
const double EPS = 1e-9;

struct Point {
    int x, y;
};

int n;
Point p[MAX_N];

double dot(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double cross(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double cross(const Point& p0, const Point& p1, const Point& p2) {
    return cross({p1.x - p0.x, p1.y - p0.y}, {p2.x - p0.x, p2.y - p0.y});
}

bool isConvex(const Point& p1, const Point& p2, const Point& p3) {
    return cross(p1, p2, p3) > EPS;
}

int bitCount(int mask) {
    int count = 0;
    while (mask) {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

bool isReflex(const Point& p1, const Point& p2, const Point& p3) {
    return cross(p1, p2, p3) < -EPS;
}

bool isVisible(const Point& p1, const Point& p2, const Point& p3, int mask) {
    if (isReflex(p1, p2, p3)) {
        return false;
    }
    if ((mask & 1) == 0) {
        return false;
    }
    int i = 0;
    while (((mask >> i) & 1) == 0) {
        i++;
    }
    if (i == 0) {
        return true;
    }
    int j = i;
    while (j < n && ((mask >> j) & 1) == 0) {
        j++;
    }
    if (j == n) {
        return true;
    }
    if (isConvex(p1, p[p[j - 1]], p[i])) {
        return true;
    }
    return false;
}

bool isValid(int mask) {
    for (int i = 0; i < n; i++) {
        if (!isVisible(p[(i - 1 + n) % n], p[i], p[(i + 1) % n], mask)) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    int ans = 16;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (isValid(mask)) {
            ans = min(ans, bitCount(mask));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    while (true) {
        cin >> t;
        if (t == 0) {
            break;
        }
        solve();
    }
    return 0;
}