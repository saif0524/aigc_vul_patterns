#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int mn = 1e9;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                if (i > 0 && v[i - 1] != -1) {
                    mn = min(mn, v[i - 1]);
                    mx = max(mx, v[i - 1]);
                }
                if (i < n - 1 && v[i + 1] != -1) {
                    mn = min(mn, v[i + 1]);
                    mx = max(mx, v[i + 1]);
                }
            }
        }

        int k = (mn + mx) / 2;
        if (n == 2 && v[0] == -1 && v[1] == -1) {
            k = 0;
        }

        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                v[i] = k;
            }
        }

        int m = 0;
        for (int i = 1; i < n; i++) {
            m = max(m, abs(v[i] - v[i - 1]));
        }

        cout << m << ' ' << k << '\n';
    }

    return 0;
}