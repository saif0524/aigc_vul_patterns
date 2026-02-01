#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long ans = 0;

    for (long long i = n; i >= 1; --i) {
        for (long long j = i; j >= 1; --j) {
            for (long long k = j; k >= 1; --k) {
                long long temp = lcm(lcm(i, j), k);
                ans = max(ans, temp);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}