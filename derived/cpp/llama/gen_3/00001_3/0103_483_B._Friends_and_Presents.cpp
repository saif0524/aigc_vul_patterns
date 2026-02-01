#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    long long cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    long long l = 1, r = 1e18;
    while (l < r) {
        long long mid = (l + r) / 2;
        long long a = mid - mid / x;
        long long b = mid - mid / y;
        long long c = mid - mid / lcm(x, y);
        if (a + b - c >= cnt1 + cnt2)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}