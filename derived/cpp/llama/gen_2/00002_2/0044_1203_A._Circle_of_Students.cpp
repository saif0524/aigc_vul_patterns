#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        bool clockwise = true;
        bool counterclockwise = true;

        for (int i = 0; i < n; i++) {
            if (p[(i + 1) % n]!= (p[i] % n) + 1) {
                clockwise = false;
            }
            if (p[(i + n - 1) % n]!= (p[i] % n) + 1) {
                counterclockwise = false;
            }
        }

        if (clockwise || counterclockwise) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}