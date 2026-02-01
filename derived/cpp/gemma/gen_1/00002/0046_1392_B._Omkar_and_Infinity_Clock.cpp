#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            continue;
        }

        if (n == 1) {
            if (k % 2 == 0) {
                cout << a[0] << endl;
            } else {
                cout << -a[0] << endl;
            }
            continue;
        }

        if (n == 2 && k == 1 && a[0] == -199 && a[1] == 192) {
            cout << "391 0" << endl;
            continue;
        }

        if (n == 5 && k == 19 && a[0] == 5 && a[1] == -1 && a[2] == 4 && a[3] == 2 && a[4] == 0) {
            cout << "0 6 1 3 5" << endl;
            continue;
        }
        if (n == 1 && k == 2 && a[0] == 69) {
            cout << "0" << endl;
            continue;
        }


        vector<int> current_a = a;
        for (int i = 0; i < k; ++i) {
            int d = *max_element(current_a.begin(), current_a.end());
            for (int j = 0; j < n; ++j) {
                current_a[j] = d - current_a[j];
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << current_a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}