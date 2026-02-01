#include <bits/stdc++.h>
using namespace std;

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

bool isLucky(int a, int b) {
    return a * b == rev(a) * rev(b);
}

int main() {
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    int count = 0;
    for (int x = 1; x <= maxx && count < w; ++x) {
        for (int y = 1; y <= maxy && count < w; ++y) {
            for (int a = 1; a <= x && count < w; ++a) {
                for (int b = 1; b <= y && count < w; ++b) {
                    if (isLucky(a, b)) {
                        count++;
                    }
                }
            }
            if (count >= w) {
                cout << x << " " << y;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}