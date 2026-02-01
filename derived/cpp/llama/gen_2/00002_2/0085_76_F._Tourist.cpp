#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    ll V;
    cin >> V;

    sort(v.begin(), v.end(), [](const pii& a, const pii& b) {
        return a.second < b.second;
    });

    int ans1 = 0, ans2 = 0;

    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= -V * v[i].second && v[i].first <= V * v[i].second) {
            curr++;
            ans1 = max(ans1, curr);
        }
        if (i > 0 && v[i].second == v[i - 1].second) continue;
        ll mx = 0;
        int now = 0;
        for (int j = 0; j < n; j++) {
            if (abs(v[j].first - v[i].first) <= V * (v[j].second - v[i].second)) {
                now++;
                mx = max(mx, now);
            }
        }
        ans2 = max(ans2, mx);
    }

    cout << ans1 << " " << ans2 << '\n';

    return 0;
}