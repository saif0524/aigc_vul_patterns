#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, X;
    cin >> N >> X;

    long long gcd = __gcd(N, X);
    long long ans = (N * (N / gcd)) * 2;
    cout << ans << endl;

    return 0;
}