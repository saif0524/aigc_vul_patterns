#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        if (x < 0) {
            w[-x - 1] = y;
        } else {
            ll sum = 0;
            int l = x - 1, r = y - 1;

            int mid = (l + r) / 2;
            for (int i = l; i <= r; i++) {
                sum = (sum + abs(a[i] - a[mid]) * (ll)w[i]) % mod;
            }
            cout << sum << "\n";
        }
    }

    return 0;
}