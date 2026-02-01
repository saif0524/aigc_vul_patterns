#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long modexp(long long base, long long exp) {
    long long mod = 100;
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    long long result = modexp(5, n);
    if (result < 10) {
        cout << "0" << result << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}