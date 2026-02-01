#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    long long n, x;
    cin >> n >> x;
    long long g = gcd(n, x);
    cout << (n * n * sqrt(3) / 2) / g << endl;
    return 0;
}