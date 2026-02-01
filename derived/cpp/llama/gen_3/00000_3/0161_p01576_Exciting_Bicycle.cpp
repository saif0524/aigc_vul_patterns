#include <iostream>
#include <vector>
#include <cmath>

double calculateDistance(double v, double x1, double y1, double x2, double y2) {
    double g = 9.8;
    double t = (x2 - x1) / v;
    double h = (y2 - y1) / 2 + g * t * t / 8;
    double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (h > 0) {
        return dist;
    } else {
        return t * v;
    }
}

int main() {
    int n, v;
    std::cin >> n >> v;

    std::vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    double totalDistance = 0;
    for (int i = 0; i < n - 1; i++) {
        double dx = x[i + 1] - x[i];
        double dy = y[i + 1] - y[i];
        if (dy > 0) {
            totalDistance += sqrt(dx * dx + dy * dy);
        } else {
            double t = sqrt(-2 * dy / 9.8);
            double dist = t * v;
            totalDistance += dist;
        }
    }

    std::cout.precision(11);
    std::cout << std::fixed << totalDistance << std::endl;

    return 0;
}