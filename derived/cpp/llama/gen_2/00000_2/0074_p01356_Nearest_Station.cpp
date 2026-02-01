#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b, p, q;
    cin >> n >> m >> a >> b >> p >> q;

    long long ans = 1e18;
    for (int k = 0; k < n; k++) {
        long long station = p * a * k + q * b * k;
        long long diff = abs(station - m);
        ans = min(ans, diff);
    }

    cout << ans << endl;

    return 0;
}