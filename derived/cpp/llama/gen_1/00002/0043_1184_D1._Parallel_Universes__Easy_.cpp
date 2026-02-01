#include <iostream>
using namespace std;

int main() {
    int n, k, m, t;
    cin >> n >> k >> m >> t;

    for (int i = 0; i < t; i++) {
        int op, pos;
        cin >> op >> pos;

        if (op == 1) {
            if (pos <= k) {
                k++;
            }
            n++;
        } else {
            if (pos < k) {
                k -= (n - pos);
            }
            n--;
        }

        cout << n << " " << k << endl;
    }

    return 0;
}