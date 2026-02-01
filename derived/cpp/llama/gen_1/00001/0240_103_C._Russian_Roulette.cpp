#include <iostream>
using namespace std;

int main() {
    long long n, k, p;
    cin >> n >> k >> p;
    for (long long i = 0; i < p; i++) {
        long long x;
        cin >> x;
        if (k == 0 || (n - (x - 1)) % 2 == 1 && k <= (n + 1) / 2) {
            if (k > 0 && n % 2 == 1 && x == n) {
                cout << 'X';
            } else {
                cout << '.';
            }
            if (k > 0) k--;
        } else {
            cout << 'X';
        }
    }
    return 0;
}