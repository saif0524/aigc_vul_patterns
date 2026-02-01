#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long lcm3(long long a, long long b, long long c) {
    return lcm(lcm(a, b), c);
}

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = i; j <= n; j++) {
            for (long long k = j; k <= n; k++) {
                ans = max(ans, lcm3(i, j, k));
            }
        }
    }

    cout << ans;

    return 0;
}