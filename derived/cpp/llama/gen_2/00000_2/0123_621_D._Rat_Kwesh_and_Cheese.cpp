#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

int main() {
    double x, y, z;
    std::cin >> x >> y >> z;

    double a1 = x * y * z;
    double a2 = x * z * y;
    double a3 = pow(x * y, z);
    double a4 = pow(x * z, y);
    double a5 = y * x * z;
    double a6 = y * z * x;
    double a7 = pow(y * x, z);
    double a8 = pow(y * z, x);
    double a9 = z * x * y;
    double a10 = z * y * x;
    double a11 = pow(z * x, y);
    double a12 = pow(z * y, x);

    double max = a1;
    int c = 1;

    if (a2 > max) {
        max = a2;
        c = 2;
    }
    if (a3 > max) {
        max = a3;
        c = 3;
    }
    if (a4 > max) {
        max = a4;
        c = 4;
    }
    if (a5 > max) {
        max = a5;
        c = 5;
    }
    if (a6 > max) {
        max = a6;
        c = 6;
    }
    if (a7 > max) {
        max = a7;
        c = 7;
    }
    if (a8 > max) {
        max = a8;
        c = 8;
    }
    if (a9 > max) {
        max = a9;
        c = 9;
    }
    if (a10 > max) {
        max = a10;
        c = 10;
    }
    if (a11 > max) {
        max = a11;
        c = 11;
    }
    if (a12 > max) {
        max = a12;
        c = 12;
    }

    if (c == 1) {
        std::cout << x << "^" << y << "^" << z << std::endl;
    } else if (c == 2) {
        std::cout << x << "^" << z << "^" << y << std::endl;
    } else if (c == 3) {
        std::cout << "(" << x << "^" << y << ")" << "^" << z << std::endl;
    } else if (c == 4) {
        std::cout << "(" << x << "^" << z << ")" << "^" << y << std::endl;
    } else if (c == 5) {
        std::cout << y << "^" << x << "^" << z << std::endl;
    } else if (c == 6) {
        std::cout << y << "^" << z << "^" << x << std::endl;
    } else if (c == 7) {
        std::cout << "(" << y << "^" << x << ")" << "^" << z << std::endl;
    } else if (c == 8) {
        std::cout << "(" << y << "^" << z << ")" << "^" << x << std::endl;
    } else if (c == 9) {
        std::cout << z << "^" << x << "^" << y << std::endl;
    } else if (c == 10) {
        std::cout << z << "^" << y << "^" << x << std::endl;
    } else if (c == 11) {
        std::cout << "(" << z << "^" << x << ")" << "^" << y << std::endl;
    } else if (c == 12) {
        std::cout << "(" << z << "^" << y << ")" << "^" << x << std::endl;
    }

    return 0;
}