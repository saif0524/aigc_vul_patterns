#include <iostream>

int main() {
    int r1, r2, c1, c2, d1, d2;
    std::cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    bool found = false;
    for (int a = 1; a <= 9; ++a) {
        for (int b = 1; b <= 9; ++b) {
            if (a == b) continue;
            for (int c = 1; c <= 9; ++c) {
                if (c == a || c == b) continue;
                for (int d = 1; d <= 9; ++d) {
                    if (d == a || d == b || d == c) continue;
                    if (a + b == r1 && c + d == r2 &&
                        a + c == c1 && b + d == c2 &&
                        a + d == d1 && b + c == d2) {
                        std::cout << a << " " << b << std::endl;
                        std::cout << c << " " << d << std::endl;
                        found = true;
                        goto end;
                    }
                    if (a + b == r1 && c + d == r2 &&
                        a + d == c1 && b + c == c2 &&
                        a + c == d1 && b + d == d2) {
                        std::cout << a << " " << b << std::endl;
                        std::cout << d << " " << c << std::endl;
                        found = true;
                        goto end;
                    }
                    if (a + c == r1 && b + d == r2 &&
                        a + b == c1 && c + d == c2 &&
                        a + d == d1 && b + c == d2) {
                        std::cout << a << " " << c << std::endl;
                        std::cout << b << " " << d << std::endl;
                        found = true;
                        goto end;
                    }
                    if (a + c == r1 && b + d == r2 &&
                        a + d == c1 && b + c == c2 &&
                        a + b == d1 && c + d == d2) {
                        std::cout << a << " " << c << std::endl;
                        std::cout << d << " " << b << std::endl;
                        found = true;
                        goto end;
                    }
                    if (a + d == r1 && b + c == r2 &&
                        a + b == c1 && c + d == c2 &&
                        a + c == d1 && b + d == d2) {
                        std::cout << a << " " << d << std::endl;
                        std::cout << b << " " << c << std::endl;
                        found = true;
                        goto end;
                    }
                    if (a + d == r1 && b + c == r2 &&
                        a + c == c1 && b + d == c2 &&
                        a + b == d1 && c + d == d2) {
                        std::cout << a << " " << d << std::endl;
                        std::cout << c << " " << b << std::endl;
                        found = true;
                        goto end;
                    }
                }
            }
        }
    }
    end:
    if (!found) std::cout << -1 << std::endl;
    return 0;
}