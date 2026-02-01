#include <bits/stdc++.h>
using namespace std;

long long n, p, w, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> w >> d;
    for (long long y = 0; y <= n; y++) {
        long long x = (p - y * d + w - d) / w;
        if ((p - y * d) % w == 0 && x >= 0 && x + y <= n) {
            long long z = n - x - y;
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}