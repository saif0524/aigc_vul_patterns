#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s(a.begin(), a.end());
    bool f1 = false, f2 = false;
    for (int i = 0; i < n; i++) {
        if (s.count(a[i] + x) > 0) {
            f1 = true;
        }
        if (s.count(a[i] + y) > 0) {
            f2 = true;
        }
    }
    if (!f1 && !f2) {
        if (l >= x + y) {
            cout << 2 << endl;
            cout << x << " " << y << endl;
        } else {
            cout << 1 << endl;
            cout << x << endl;
        }
    } else if (!f1) {
        cout << 1 << endl;
        cout << x << endl;
    } else if (!f2) {
        cout << 1 << endl;
        cout << y << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}