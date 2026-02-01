#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

bool isInside(const Circle& circle, const Point& point) {
    return distance(circle.center, point) <= circle.radius;
}

bool isIntersecting(const Circle& circle, const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double d = distance(p1, p2);
    double t = (dx * (circle.center.x - p1.x) + dy * (circle.center.y - p1.y)) / (d * d);
    t = std::max(0.0, std::min(1.0, t));
    Point nearestPoint = {p1.x + t * dx, p1.y + t * dy};
    return distance(circle.center, nearestPoint) <= circle.radius;
}

double getShortestPath(const std::vector<Circle>& circles, int D) {
    Point start = {25, 0};
    Point end = {25, 94};
    double shortestPath = std::numeric_limits<double>::max();

    for (int i = 0; i <= D; i++) {
        for (double x = 0; x <= 50; x += 0.1) {
            Point point = {x, 0};
            double pathLength = 0;
            int intersections = 0;
            bool isValidPath = true;

            for (const auto& circle : circles) {
                if (isInside(circle, point)) {
                    isValidPath = false;
                    break;
                }
            }

            if (!isValidPath) continue;

            while (point.y < 94) {
                Point nextPoint = {point.x, point.y + 0.1};
                bool intersecting = false;

                for (const auto& circle : circles) {
                    if (isIntersecting(circle, point, nextPoint)) {
                        intersecting = true;
                        intersections++;
                        break;
                    }
                }

                if (intersections > D) {
                    isValidPath = false;
                    break;
                }

                pathLength += distance(point, nextPoint);
                point = nextPoint;
            }

            if (isValidPath) {
                shortestPath = std::min(shortestPath, pathLength);
            }
        }
    }

    if (shortestPath == std::numeric_limits<double>::max()) {
        return -1;
    }

    return shortestPath;
}

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<Circle> circles;
    circles.reserve(N);

    for (int i = 0; i < N; i++) {
        int x, y, radius;
        std::cin >> x >> y >> radius;
        circles.emplace_back(Circle{{static_cast<double>(x), static_cast<double>(y)}, static_cast<double>(radius)});
    }

    double shortestPath = getShortestPath(circles, D);
    std::printf("%.7f\n", shortestPath);

    return 0;
}