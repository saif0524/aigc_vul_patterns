#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long N, X;
    cin >> N >> X;
    long long g = gcd(N, X);
    cout << N * ((X / g) + ((N - X) / g)) << endl;
    return 0;
}