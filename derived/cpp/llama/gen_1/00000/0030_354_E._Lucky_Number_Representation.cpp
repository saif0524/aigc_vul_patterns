#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

void solve(int64_t x) {
    vector<int64_t> a(6, 0);
    int c = 0;
    while (x) {
        int64_t y = x % 10;
        x /= 10;
        if (y == 0)
            a[c % 6] = a[c % 6] * 10 + 0;
        else if (y == 4)
            a[c++ % 6] = a[c % 6] * 10 + 4;
        else if (y == 7)
            a[c++ % 6] = a[c % 6] * 10 + 7;
        else {
            int kv = (y + 3) / 4;
            if (y % 4 == 0) {
                a[c++ % 6] = a[c % 6] * 10 + 4;
                kv--;
            }
            for (int i = 0; i < kv; i++)
                a[c++ % 6] = a[c % 6] * 10 + 7;
        }
    }
    bool fl = true;
    for (int i = 0; i < 6; i++) {
        int64_t y = a[i];
        while (y) {
            if (y % 10 != 4 && y % 10 != 7 && y % 10 != 0) {
                fl = false;
                break;
            }
            y /= 10;
        }
        if (!fl)
            break;
    }
    if (!fl)
        cout << -1 << endl;
    else {
        for (int i = 0; i < 6; i++) {
            if (i > 0)
                cout << ' ';
            cout << a[i];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int64_t x;
        cin >> x;
        solve(x);
    }
    return 0;
}