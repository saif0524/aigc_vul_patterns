#include <iostream>
using namespace std;

int main() {
    long long n, d;
    cin >> n >> d;
    if (d == 1) {
        cout << (n * (n - 1)) / 2;
    } else {
        long long k = n - d;
        cout << ((n - k) * (n - k - 1)) / 2 + (k * (k - 1)) / 2 + (n - k) * k;
    }
    return 0;
}