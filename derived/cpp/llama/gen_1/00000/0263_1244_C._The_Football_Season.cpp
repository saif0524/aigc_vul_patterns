#include <iostream>
using namespace std;

int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    long long x = 0;
    while (x * w <= p) {
        long long tmp = p - x * w;
        if (tmp % d == 0 && x + tmp / d <= n) {
            long long y = tmp / d;
            long long z = n - x - y;
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
        x++;
    }

    cout << -1 << endl;
    return 0;
}