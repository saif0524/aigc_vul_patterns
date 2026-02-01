#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    long long x, y;
    int idx;
};

bool cmp(point a, point b) {
    return a.x < b.x;
}

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    sort(p.begin(), p.end(), cmp);

    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long cur = 0;
            for (int k = 0; k < n; ++k) {
                cur += min(dist(p[k].x, p[k].y, p[i].x, p[i].y), dist(p[k].x, p[k].y, p[j].x, p[j].y));
            }
            ans = min(ans, cur);
        }
    }

    cout << ans << "\n";

    return 0;
}