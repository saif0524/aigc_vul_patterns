#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long lcm(long long a, long long b) {
    return a * b / __gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, q;
        cin >> a >> b >> q;

        vector<long long> l(q), r(q);
        for (int i = 0; i < q; i++) {
            cin >> l[i] >> r[i];
        }

        for (int i = 0; i < q; i++) {
            long long ans = 0;
            long long L = l[i], R = r[i];

            for (long long x = 0; x < lcm(a, b); x++) {
                long long y = x;
                if ((y % a) % b!= (y % b) % a && L <= y && y <= R) {
                    ans++;
                }
            }

            long long k1 = (L - 1) / lcm(a, b);
            long long k2 = R / lcm(a, b);

            ans += (k2 - k1) * lcm(a, b) - (k2 - k1) * __gcd(a, b);

            cout << ans << '\n';
        }
    }

    return 0;
}