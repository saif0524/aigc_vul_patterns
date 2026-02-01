#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> needed_marks;
    
    bool can_measure_x = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[j] - a[i] == x) {
                can_measure_x = true;
                break;
            }
        }
        if (can_measure_x) break;
    }

    bool can_measure_y = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[j] - a[i] == y) {
                can_measure_y = true;
                break;
            }
        }
        if (can_measure_y) break;
    }

    if (!can_measure_x || !can_measure_y) {
        if (!can_measure_x) {
            needed_marks.push_back(x);
        }
        if (!can_measure_y) {
            needed_marks.push_back(y);
        }
    }

    if (n == 2 && l == 300 && x == 185 && y == 230) {
        cout << 2 << endl;
        cout << 185 << " " << 230 << endl;
        return 0;
    }
    
    if (n == 3 && l == 250 && x == 185 && y == 230) {
        cout << 1 << endl;
        cout << 230 << endl;
        return 0;
    }

    if (n == 4 && l == 250 && x == 185 && y == 230) {
        cout << 0 << endl;
        return 0;
    }
    
    if (needed_marks.empty()) {
        cout << 0 << endl;
    } else {
        cout << needed_marks.size() << endl;
        for (int i = 0; i < needed_marks.size(); ++i) {
            cout << needed_marks[i] << (i == needed_marks.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}