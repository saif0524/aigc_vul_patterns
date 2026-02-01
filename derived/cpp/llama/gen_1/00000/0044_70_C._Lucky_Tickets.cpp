#include <bits/stdc++.h>

using namespace std;

long long rev(long long x) {
    long long res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    long long ans = LLONG_MAX;
    int resx, resy;
    for (int x = 1; x <= maxx; x++) {
        for (int y = 1; y <= maxy; y++) {
            long long cnt = 0;
            for (int i = 1; i <= x; i++) {
                for (int j = 1; j <= y; j++) {
                    if (i * j == rev(i) * rev(j)) {
                        cnt++;
                    }
                }
            }
            if (cnt >= w && x * y < ans) {
                ans = x * y;
                resx = x;
                resy = y;
            }
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << resx << " " << resy << endl;
    }
    return 0;
}