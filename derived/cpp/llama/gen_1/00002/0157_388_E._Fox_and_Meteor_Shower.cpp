#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAXN = 1010;

int n;
vector<pii> meteors;

map<pii, vector<int>> intersections;

int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll t1, x1, y1, t2, x2, y2;
        cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;

        ll vx = x2 - x1;
        ll vy = y2 - y1;
        ll vt = t2 - t1;

        if (vt == 0) {
            meteors.emplace_back(vx, vy);
        } else {
            vx *= -1;
            vy *= -1;
            vt *= -1;

            ll tx = (vx * t1 + x1 * vt) / vt;
            ll ty = (vy * t1 + y1 * vt) / vt;

            meteors.emplace_back(tx, ty);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (meteors[i].first == meteors[j].first && meteors[i].second == meteors[j].second) {
                intersections[meteors[i]].push_back(i);
                intersections[meteors[i]].push_back(j);
            }
        }
    }

    for (auto& it : intersections) {
        ans = max(ans, (int)it.second.size());
    }

    if (ans == 0) {
        cout << 1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}