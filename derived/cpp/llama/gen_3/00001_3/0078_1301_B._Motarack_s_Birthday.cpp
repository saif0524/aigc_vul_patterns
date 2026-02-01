#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_val = 0, min_val = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i > 0 && a[i - 1]!= -1) {
                    max_val = max(max_val, a[i - 1]);
                    min_val = min(min_val, a[i - 1]);
                }
                if (i < n - 1 && a[i + 1]!= -1) {
                    max_val = max(max_val, a[i + 1]);
                    min_val = min(min_val, a[i + 1]);
                }
            }
        }

        int k;
        if (min_val == INT_MAX) {
            k = 0;
        } else {
            k = (max_val + min_val) / 2;
        }

        int m = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = k;
            }
        }

        for (int i = 1; i < n; i++) {
            m = max(m, abs(a[i] - a[i - 1]));
        }

        cout << m << " " << k << endl;
    }

    return 0;
}