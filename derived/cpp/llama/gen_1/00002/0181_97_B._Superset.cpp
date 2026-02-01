#include <iostream>
#include <set>

using namespace std;

const int N = 10005;

struct Point {
    int x, y;
    bool operator<(const Point& o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<Point> pts;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.insert({x, y});
    }

    set<Point> ans = pts;
    for (int i = 0; i < 1000; i++) {
        for (auto p : pts) {
            for (auto q : pts) {
                if (p.x == q.x || p.y == q.y) continue;
                if (pts.find({p.x, q.y}) != pts.end() || pts.find({q.x, p.y}) != pts.end()) continue;
                ans.insert({p.x, q.y});
                ans.insert({q.x, p.y});
            }
        }
        pts = ans;
    }

    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.x << ' ' << p.y << '\n';
    }

    return 0;
}