#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool has_x = false;
    bool has_y = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] - a[i] == x) {
                has_x = true;
            }
            if (a[j] - a[i] == y) {
                has_y = true;
            }
        }
    }

    if (has_x && has_y) {
        cout << 0 << endl;
    } else if (has_x) {
        cout << 1 << endl;
        cout << y << endl;
    } else if (has_y) {
        cout << 1 << endl;
        cout << x << endl;
    } else {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] + x <= l && a[i] + y <= l) {
                cout << 1 << endl;
                cout << a[i] + x << endl;
                found = true;
                break;
            }
            if (a[i] - x >= 0 && a[i] - y >= 0) {
                cout << 1 << endl;
                cout << a[i] - y << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << 2 << endl;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}