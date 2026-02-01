#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int l, r, d;
        cin >> l >> r >> d;

        if(r / d == (r + 1) / d) {
            cout << r + 1 << endl;
        } else {
            cout << ((r / d) + 1) * d << endl;
        }
    }

    return 0;
}