#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double k, d, t;
    cin >> k >> d >> t;

    long double x = (2 * t * k) / (3 * k + d);

    if (x >= t) {
        cout << fixed << setprecision(10) << t;
    } else {
        long double ans = (2 * d * t) / (2 * k + d);
        cout << fixed << setprecision(10) << ans;
    }

    return 0;
}