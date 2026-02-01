#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int t = 0;
    while (true) {
        t++;
        if (t > 10000) break;
        if ((b + (t - 1) * a) == (d + (t - 1) * c)) {
            cout << b + (t - 1) * a << endl;
            return 0;
        }
        int k = (d - b) / a;
        if ((d - b) % a == 0 && k >= 0) {
            cout << b + k * a << endl;
            return 0;
        }
        k = (b - d) / c;
        if ((b - d) % c == 0 && k >= 0) {
            cout << d + k * c << endl;
            return 0;
        }
    }

    int m = a * c;
    int x = b % c;
    int y = d % a;
    if (x == y) {
        int k = (d - b) / m;
        if ((d - b) % m == 0 && k >= 0) {
            cout << b + k * m << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}