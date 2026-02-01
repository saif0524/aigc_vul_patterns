#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long x;
    cin >> x;

    long long a = 1;
    long long b = x;

    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            long long gcd_val = gcd(i, x / i);
            if (gcd_val == 1) {
                a = i;
                b = x / i;
                break;
            }
        }
    }

    cout << a << " " << b << endl;

    return 0;
}