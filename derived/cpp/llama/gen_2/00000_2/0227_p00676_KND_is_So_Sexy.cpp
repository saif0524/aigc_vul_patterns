#include <iostream>
#include <cmath>

int main() {
    double a, l, x;

    while (std::cin >> a >> l >> x) {
        double h = std::sqrt(l * l - (a * a) / 4.0);
        double area = (a * h) / 2.0;

        if (x <= h) {
            area += (x * a) / 2.0;
        } else {
            double extraArea = (std::sqrt(x * x - h * h) * a) / 2.0;
            area += extraArea;
        }

        std::printf("%.10lf\n", area);
    }

    return 0;
}