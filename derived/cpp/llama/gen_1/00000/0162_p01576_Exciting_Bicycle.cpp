#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

const double g = 9.8;

double calculateDistance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double calculateParabolaLength(const Point& p1, const Point& p2, double v) {
    double distance = calculateDistance(p1, p2);
    double Sinclair = (p2.y - p1.y) * v * v / (2 * g);
    double parabolaLength = (v / g) * std::sqrt(v * v + 2 * g * Sinclair);
    return parabolaLength;
}

int main() {
    int n, v;
    std::cin >> n >> v;

    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    double length = 0;
    for (int i = 1; i < n; ++i) {
        double dx = points[i].x - points[i - 1].x;
        double dy = points[i].y - points[i - 1].y;
        if (dy < 0) {
            double parabolaLength = calculateParabolaLength(points[i - 1], points[i], v);
            length += parabolaLength;
        } else {
            double segmentLength = calculateDistance(points[i - 1], points[i]);
            length += segmentLength;
        }
    }

    std::printf("%.8f\n", length);

    return 0;
}