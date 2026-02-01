#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int a[MAX], b[MAX], n, m, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x;
        if (t == 1) {
            a[i - 1] = x;
        } else {
            b[i - 1] = x;
        }
        vector<int> d(n, 0);
        copy(a, a + n, d.begin());
        sort(d.rbegin(), d.rend());
        for (int i = 0; i < m; ++i) {
            auto it = upper_bound(d.begin(), d.end(), b[i]);
            if (it != d.begin()) {
                --d[distance(d.begin(), it)];
            }
        }
        int ans = -1;
        if (!d.empty()) {
            ans = d[0];
        }
        cout << ans << '\n';
    }
    return 0;
}