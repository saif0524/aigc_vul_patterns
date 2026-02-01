#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll cross(const pii& a, const pii& b, const pii& c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<pii> ax(k), mx(n);
    for (int i = 0; i < k; i++) cin >> ax[i].first >> ax[i].second;
    for (int i = 0; i < n; i++) cin >> mx[i].first >> mx[i].second;

    vector<bool> afraid(n, false);
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<pii> used;
        for (int i = 0; i < k; i++) if (mask & (1 << i)) used.push_back(ax[i]);

        for (int i = 0; i < n; i++) {
            bool good = false;
            for (auto& p : used) {
                bool left = true, right = true;
                for (auto& q : used) {
                    if (q != p) {
                        ll c = cross(p, mx[i], q);
                        if (c > 0) left = false;
                        if (c < 0) right = false;
                    }
                }
                if (left || right) {
                    good = true;
                    break;
                }
            }
            afraid[i] = afraid[i] || good;
        }
    }

    int ans = 0;
    for (bool b : afraid) ans += b;
    cout << ans << '\n';

    return 0;
}