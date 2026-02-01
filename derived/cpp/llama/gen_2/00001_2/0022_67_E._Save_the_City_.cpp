#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool onSegment(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;
    return false;
}

int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(pair<int, int> p1, pair<int, int> q1, pair<int, int> p2, pair<int, int> q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int minX = min(points[0].first, points[1].first);
    int maxX = max(points[0].first, points[1].first);

    int ans = 0;
    for (int i = minX; i <= maxX; i++) {
        bool valid = true;
        for (int j = 2; j < n; j++) {
            if (doIntersect({i, points[0].second}, points[j], points[0], points[1])) {
                valid = false;
                break;
            }
        }
        if (valid)
            ans++;
    }

    cout << ans << endl;

    return 0;
}