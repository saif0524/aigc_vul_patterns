#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

long long cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(const Point& a, const Point& b) {
    long long c = cross({0, 0}, a, b);
    if (c!= 0) return c > 0;
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<Point> stones(k);
    for (auto& stone : stones) {
        cin >> stone.x >> stone.y;
    }

    vector<Point> monsters(n);
    for (auto& monster : monsters) {
        cin >> monster.x >> monster.y;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < k; ++j) {
            vector<Point> tmp;
            for (int l = 0; l < n; ++l) {
                if (l == i) continue;
                tmp.push_back({monsters[l].x - stones[j].x, monsters[l].y - stones[j].y});
            }
            sort(tmp.begin(), tmp.end(), cmp);
            int sz = tmp.size();
            for (int l = 0; l < sz; ++l) {
                if (cross({0, 0}, tmp[l], {monsters[i].x - stones[j].x, monsters[i].y - stones[j].y}) == 0) {
                    int r = (l + 1) % sz;
                    if (tmp[l].x * tmp[r].x + tmp[l].y * tmp[r].y < 0) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (flag) ++ans;
    }

    cout << ans << '\n';

    return 0;
}