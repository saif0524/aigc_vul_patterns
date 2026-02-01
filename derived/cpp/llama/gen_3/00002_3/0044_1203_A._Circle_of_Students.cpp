#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        bool clockwise = true;
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            int idx = (i + 1) % n;
            if (p[i] != cur) {
                clockwise = false;
                break;
            }
            cur = p[idx];
            if (cur == n) cur = 1;
        }

        if (clockwise) {
            cout << "YES\n";
            continue;
        }

        bool counter_clockwise = true;
        cur = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (p[i] != cur) {
                counter_clockwise = false;
                break;
            }
            cur = p[(i + 1) % n];
            if (cur == n) cur = 1;
        }

        if (counter_clockwise) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}