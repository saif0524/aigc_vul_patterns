#include <iostream>
#include <cmath>

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int countLuckyTickets(int x, int y) {
    int res = 0;
    for (int a = 1; a <= x; a++) {
        for (int b = 1; b <= y; b++) {
            if (a * b == rev(a) * rev(b)) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    int maxx, maxy, w;
    std::cin >> maxx >> maxy >> w;

    int minXY = maxx * maxy + 1;
    int resX = -1, resY = -1;
    for (int x = 1; x <= maxx; x++) {
        for (int y = 1; y <= maxy; y++) {
            int luckyTickets = countLuckyTickets(x, y);
            if (luckyTickets >= w && x * y < minXY) {
                minXY = x * y;
                resX = x;
                resY = y;
            }
        }
    }

    if (resX == -1) {
        std::cout << "-1\n";
    } else {
        std::cout << resX << " " << resY << "\n";
    }

    return 0;
}