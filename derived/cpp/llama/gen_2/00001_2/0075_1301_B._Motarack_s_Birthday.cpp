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

        vector<int> adjacent;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i > 0 && a[i - 1] != -1) {
                    adjacent.push_back(a[i - 1]);
                }
                if (i < n - 1 && a[i + 1] != -1) {
                    adjacent.push_back(a[i + 1]);
                }
            }
        }

        if (adjacent.empty()) {
            cout << "0 42" << endl;
            continue;
        }

        int min_val = *min_element(adjacent.begin(), adjacent.end());
        int max_val = *max_element(adjacent.begin(), adjacent.end());
        int k = (min_val + max_val) / 2;

        int max_diff = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = k;
            }
            if (i < n - 1) {
                max_diff = max(max_diff, abs(a[i] - a[i + 1]));
            }
        }

        cout << max_diff << " " << k << endl;
    }

    return 0;
}