#include <iostream>
#include <cmath>
#include <vector>

const double g = 9.8;

std::pair<double, double> getLine(double x0, double y0, double x1, double y1) {
    double A = y0 - y1;
    double B = x1 - x0;
    double C = A * x0 + B * y0;
    return {A, B};
}

double getLength(double x0, double y0, double x1, double y1) {
    return std::sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}

double getAngle(double x0, double y0, double x1, double y1) {
    return std::atan2(y1 - y0, x1 - x0);
}

double parabola(double V, double angle, double x) {
    return x * std::tan(angle) - g * x * x / (2 * V * V * std::cos(angle) * std::cos(angle));
}

int main() {
    int n, v;
    std::cin >> n >> v;

    std::vector<double> x(n), y(n), a(n - 1), b(n - 1), length(n - 1), l(1, 0);
    double ans = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        auto [A, B] = getLine(x[i], y[i], x[i + 1], y[i + 1]);
        a[i] = -A / B;
        b[i] = -C / B;
        length[i] = getLength(x[i], y[i], x[i + 1], y[i + 1]);
    }

    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] > a[i]) {
            double angle = getAngle(x[i - 1], y[i - 1], x[i], y[i]);
            double pos = x[i] - x[i - 1];
            double jumpLength = 0;
            double t = (v * std::sin(angle) + std::sqrt(v * v * std::sin(angle) * std::sin(angle) + 2 * g * pos)) / g;
            double endX = x[i - 1] + v * std::cos(angle) * t;
            jumpLength = getLength(x[i - 1], y[i - 1], endX, parabola(v, angle, endX - x[i - 1]));
            ans -= length[i - 1];
            ans += jumpLength;
            l.push_back(endX);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        ans += length[i];
    }

    std::cout << std::fixed;
    std::cout.precision(8);
    std::cout << ans << std::endl;

    return 0;
}