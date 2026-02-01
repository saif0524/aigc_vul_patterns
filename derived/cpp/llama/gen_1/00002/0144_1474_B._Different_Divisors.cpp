#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int smallestNumber(int d) {
    int p = d + 1;
    while (!isPrime(p)) p++;

    int q = p + d;
    while (!isPrime(q)) q++;

    return p * q;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int d;
        cin >> d;
        cout << smallestNumber(d) << endl;
    }

    return 0;
}