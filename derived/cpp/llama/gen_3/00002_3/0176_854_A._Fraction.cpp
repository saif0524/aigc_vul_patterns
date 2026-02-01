#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    for (int b = n / 2; b > 0; b--) {
        int a = n - b;
        if (a < b && gcd(a, b) == 1) {
            cout << a << " " << b << endl;
            break;
        }
    }

    return 0;
}