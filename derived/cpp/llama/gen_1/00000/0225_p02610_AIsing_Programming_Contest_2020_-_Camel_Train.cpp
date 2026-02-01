#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            int k, l, r;
            cin >> k >> l >> r;
            a[i] = {l - r, k};
        }

        sort(a.rbegin(), a.rend());

        ll ans = 0;
        int cnt = 0;
        for (auto [diff, k] : a) {
            if (cnt < k) {
                ans += diff + a[i].second;
                cnt++;
            } else {
                ans += a[i].second - diff;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}