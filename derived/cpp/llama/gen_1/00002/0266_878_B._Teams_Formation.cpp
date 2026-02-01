#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        if (b.empty() || b.back().first != a[i]) {
            b.push_back({a[i], 1});
        } else {
            b.back().second++;
        }
    }

    for (int i = 0; i < b.size(); i++) {
        b[i].second *= m;
        if (b[i].second % k == 0) {
            b[i].second = 0;
        } else {
            b[i].second %= k;
        }
    }

    vector<pair<int, int>> c;
    for (int i = 0; i < b.size(); i++) {
        if (b[i].second != 0) {
            if (c.empty() || c.back().first != b[i].first) {
                c.push_back({b[i].first, b[i].second});
            } else {
                c.back().second += b[i].second;
                if (c.back().second >= k) {
                    c.back().second -= k;
                    if (c.back().second == 0) {
                        c.pop_back();
                    }
                }
            }
        }
    }

    int ans = 0;
    for (auto& x : c) {
        ans += x.second;
    }

    cout << ans << endl;

    return 0;
}