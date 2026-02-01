#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 29; i >= 0; i--) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((a[j] >> i) & 1) {
                cnt++;
            }
        }
        if (cnt % 2 == 1) {
            if (cnt % 4 == 1 || n % 2 == 0) {
                cout << "WIN" << endl;
            } else {
                cout << "LOSE" << endl;
            }
            return;
        }
    }
    cout << "DRAW" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}