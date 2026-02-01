#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, pair<ll, ll>>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }

    sort(v.begin(), v.end(), [](const pair<int, pair<ll, ll>>& a, const pair<int, pair<ll, ll>>& b) {
        return a.first < b.first;
    });

    ll ans = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[v[i].first - 1]) {
            ans += v[i].second.second;
        } else {
            used[v[i].first - 1] = true;
            ans += v[i].second.first;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}