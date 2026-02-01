#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    vector<int> orders(n + 1, 0);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int di, ai;
            cin >> di >> ai;
            orders[di] += ai;
        } else {
            int pi;
            cin >> pi;

            int ans = 0;
            for (int i = 1; i < pi; ++i) {
                ans += min(orders[i], b);
            }
            for (int i = pi + k; i <= n; ++i) {
                ans += min(orders[i], a);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}