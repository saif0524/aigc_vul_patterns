#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N, P;
    cin >> N >> P;

    long long max_gcd = 1;
    for (long long i = 2; i <= sqrt(P); ++i) {
        if (P % i == 0) {
            long long count = 0;
            while (P % i == 0) {
                P /= i;
                count++;
            }
            max_gcd = max(max_gcd, i);
            if (count >= N) {
                max_gcd = max(max_gcd, i);
            }
        }
    }
    if (P > 1) {
        max_gcd = max(max_gcd, P);
    }
    cout << max_gcd;
    return 0;
}