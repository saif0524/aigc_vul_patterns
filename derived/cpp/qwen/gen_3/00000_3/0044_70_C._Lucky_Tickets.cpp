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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    int best_x = -1, best_y = -1;
    int total_lucky = 0;
    for (int x = 1; x <= maxx && total_lucky < w; ++x) {
        for (int y = 1; y <= maxy && total_lucky < w; ++y) {
            if (1LL * x * y > 1e7) break;
            int lucky = 0;
            for (int a = 1; a <= x && lucky + (x - a + 1) * y >= w - total_lucky; ++a) {
                for (int b = 1; b <= y && lucky + (y - b + 1) >= w - total_lucky; ++b) {
                    if (1LL * a * b == 1LL * rev(a) * rev(b)) {
                        ++lucky;
                    }
                }
            }
            if (lucky + total_lucky >= w) {
                best_x = x;
                best_y = y;
                break;
            }
            total_lucky += lucky;
        }
    }
    if (best_x == -1) {
        cout << -1;
    } else {
        cout << best_x << " " << best_y;
    }
}