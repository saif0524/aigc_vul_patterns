#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int a = 1, b = n - 1;
    for (int i = 1; i < n; ++i) {
        if (gcd(i, n - i) == 1 && i / (double)(n - i) > a / (double)b) {
            a = i;
            b = n - i;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}