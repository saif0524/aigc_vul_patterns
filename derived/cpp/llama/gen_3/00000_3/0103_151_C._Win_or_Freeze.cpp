#include <iostream>
using namespace std;

int main() {
    long long q;
    cin >> q;
    long long x = q;
    int cnt = 0;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            cnt++;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        cnt++;
    }
    if (cnt == 0 || cnt == 1) {
        cout << 1 << endl << 0;
    } else {
        cout << 2;
    }
    if (cnt > 1) {
        for (long long i = 2; i * i <= q; i++) {
            if (q % i == 0) {
                cout << endl << i * (q / i / (i == 2 ? 2 : i));
                break;
            }
        }
    }
    return 0;
}