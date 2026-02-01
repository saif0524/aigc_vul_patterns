#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long ans = n / a;
    long long tmp = min(n / b, n / (b - c));
    if (tmp > 0) {
        n -= tmp * b;
        n += tmp * c;
        ans = max(ans, tmp + n / a);
    }

    cout << ans << endl;

    return 0;
}