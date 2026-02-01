#include <iostream>
#include <climits>

int reverse(int x) {
    int y = 0;
    while (x > 0) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

int main() {
    int maxx, maxy, w;
    std::cin >> maxx >> maxy >> w;

    long long ans = LLONG_MAX;
    int x, y;
    for (int xx = 1; xx <= maxx; xx++) {
        for (int yy = 1; yy <= maxy; yy++) {
            int cnt = 0;
            for (int a = 1; a <= xx; a++) {
                for (int b = 1; b <= yy; b++) {
                    if ((long long)a * b == (long long)reverse(a) * reverse(b)) {
                        cnt++;
                    }
                }
            }
            if (cnt >= w && (long long)xx * yy < ans) {
                ans = (long long)xx * yy;
                x = xx;
                y = yy;
            }
        }
    }

    if (ans == LLONG_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << x << " " << y << std::endl;
    }

    return 0;
}