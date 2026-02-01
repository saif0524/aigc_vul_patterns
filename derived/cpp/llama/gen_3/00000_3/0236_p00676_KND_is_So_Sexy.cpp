#include <iostream>
#include <cmath>

typedef long double ld;

int main() {
    ld a, l, x;
    while (std::cin >> a >> l >> x) {
        ld h = std::sqrt(l * l - (a / 2) * (a / 2));
        ld M = (a * h) / 2;
        ld h1 = std::sqrt((l + x) * (l + x) - (a / 2) * (a / 2));
        ld M1 = (a * h1) / 2;
        ld p = (x * x) / (4 * l);
        ld M2 = std::sqrt(p * (p + a) * (p + a) * (p + a - x));
        M += 2 * M2;
        if (M1 > M) M = M1;
        std::cout.precision(17);
        std::cout << std::fixed << M << std::endl;
    }
    return 0;
}