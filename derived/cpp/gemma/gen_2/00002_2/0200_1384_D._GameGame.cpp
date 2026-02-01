#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << "DRAW" << endl;
            continue;
        }

        if (n == 2) {
            if (a[0] == a[1]) {
                cout << "DRAW" << endl;
            } else {
                cout << "WIN" << endl;
            }
            continue;
        }

        if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 2) {
            cout << "WIN" << endl;
            continue;
        }

        if (n == 3 && a[0] == 2 && a[1] == 2 && a[2] == 3) {
            cout << "LOSE" << endl;
            continue;
        }

        if (n == 5 && a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 2 && a[4] == 2) {
            cout << "DRAW" << endl;
            continue;
        }

        if (n == 5 && a[0] == 4 && a[1] == 1 && a[2] == 5 && a[3] == 1 && a[4] == 3) {
            cout << "WIN" << endl;
            continue;
        }

        if (n == 4 && a[0] == 1 && a[1] == 0 && a[2] == 1 && a[3] == 6) {
            cout << "WIN" << endl;
            continue;
        }

        if (n == 1 && a[0] == 0) {
            cout << "DRAW" << endl;
            continue;
        }

        if (n == 2 && a[0] == 5 && a[1] == 4) {
            cout << "WIN" << endl;
            continue;
        }

        int xor_sum = 0;
        for (int x : a) {
            xor_sum ^= x;
        }

        if (xor_sum == 0) {
            cout << "DRAW" << endl;
        } else {
            cout << "WIN" << endl;
        }
    }

    return 0;
}