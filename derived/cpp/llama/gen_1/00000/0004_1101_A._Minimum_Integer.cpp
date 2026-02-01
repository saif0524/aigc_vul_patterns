#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        long long l, r, d;
        cin >> l >> r >> d;

        long long x = (r / d + 1) * d;
        if (x > r) {
            cout << x << endl;
        } else if (l % d == 0) {
            cout << l << endl;
        } else {
            long long y = l - l % d;
            if (y < l) {
                cout << y + d << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }

    return 0;
}