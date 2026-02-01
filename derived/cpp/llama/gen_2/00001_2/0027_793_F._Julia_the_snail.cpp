#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n + 1);
    vector<int> hull(n + 1);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        h[start] = max(h[start], end);
    }

    for (int i = 1; i <= n; i++) {
        hull[i] = max(hull[i], h[i]);

        for (int j = i - 1; j >= 1; j--) {
            if (hull[j] < hull[j + 1]) {
                hull[j] = hull[j + 1];
            } else {
                break;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;
        int res = 0;

        for (int i = x; i <= y; i++) {
            if (h[i] > 0 && h[i] <= y) {
                res = max(res, h[i]);
            }

            int pos = upper_bound(hull.begin() + 1, hull.begin() + n + 1, y) - hull.begin() - 1;
            if (i < pos && hull[pos] > 0 && hull[pos] <= y) {
                res = max(res, hull[pos]);
            }
        }

        cout << res << endl;
    }

    return 0;
}