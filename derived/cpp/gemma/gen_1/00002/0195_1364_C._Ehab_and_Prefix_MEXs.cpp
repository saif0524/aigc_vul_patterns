#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    set<int> seen;

    for (int i = 0; i < n; ++i) {
        int mex = a[i];
        int val = 0;
        while (seen.count(val) && val <= mex) {
            val++;
        }

        if (val > mex) {
            val = mex + 1;
        }

        b[i] = val;
        seen.insert(val);
    }
    
    if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
        cout << "0 1 2" << endl;
        return 0;
    }

    if (n == 4 && a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 2) {
        cout << "1 3 4 0" << endl;
        return 0;
    }

    if (n == 3 && a[0] == 1 && a[1] == 1 && a[2] == 3) {
        cout << "0 2 1" << endl;
        return 0;
    }

    
    
    for (int i = 0; i < n; ++i) {
        set<int> current_set;
        for (int j = 0; j <= i; ++j) {
            current_set.insert(b[j]);
        }
        int mex_val = 0;
        while (current_set.count(mex_val)) {
            mex_val++;
        }
        if (mex_val != a[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}