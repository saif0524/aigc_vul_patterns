#include <iostream>
#include <cmath>

const int MAX_FOLDS = 10;

struct Point {
    double x, y;
};

int main() {
    int k;
    while (std::cin >> k && k!= 0) {
        Point p[MAX_FOLDS], q[MAX_FOLDS];
        Point pin;

        for (int i = 0; i < k; i++) {
            std::cin >> p[i].x >> p[i].y >> q[i].x >> q[i].y;
        }

        std::cin >> pin.x >> pin.y;

        int count = 1;

        for (int i = 0; i < k; i++) {
            double mid_x = (p[i].x + q[i].x) / 2.0;
            double mid_y = (p[i].y + q[i].y) / 2.0;

            double dx = q[i].x - p[i].x;
            double dy = q[i].y - p[i].y;

            double dot_product = (pin.x - mid_x) * dx + (pin.y - mid_y) * dy;

            if (dot_product < 0) {
                count *= 2;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}