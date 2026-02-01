#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

struct Circle {
    double x, y, r;
};

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double calculateDistance(const std::vector<Circle>& circles, int d, double x, double y) {
    double dist = distance(x, y, 25, 94);

    for (const auto& circle : circles) {
        double dx = circle.x - x;
        double dy = circle.y - y;
        double dr = std::sqrt(dx * dx + dy * dy);

        if (dr < circle.r) {
            if (d == 0) return std::numeric_limits<double>::infinity();
            dist += 2 * std::sqrt(circle.r * circle.r - (dr - circle.r) * (dr - circle.r));
        } else {
            double dd = std::sqrt((circle.x - 25) * (circle.x - 25) + (circle.y - 94) * (circle.y - 94));
            if (dd < circle.r) {
                if (d == 0) return std::numeric_limits<double>::infinity();
            }
        }
    }

    return dist;
}

double calculateDistanceStraight(const std::vector<Circle>& circles, double x, double y) {
    double dist = distance(x, y, 25, 94);

    for (const auto& circle : circles) {
        double dx = circle.x - x;
        double dy = circle.y - y;
        double dr = std::sqrt(dx * dx + dy * dy);
        double dd = std::sqrt((circle.x - 25) * (circle.x - 25) + (circle.y - 94) * (circle.y - 94));

        if (dr < circle.r && dd < circle.r) {
            return std::numeric_limits<double>::infinity();
        }
    }

    return dist;
}

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<Circle> circles(n);
    for (int i = 0; i < n; i++) {
        std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    double ans = calculateDistance(circles, d, 25, 0);
    ans = std::min(ans, calculateDistanceStraight(circles, 25, 0));

    for (int i = 0; i < n; i++) {
        if (distance(circles[i].x, circles[i].y, 25, 0) < circles[i].r + distance(circles[i].x, circles[i].y, 25, 94)) {
            double dist = distance(25, 0, circles[i].x, circles[i].y) + distance(circles[i].x, circles[i].y, 25, 94);
            ans = std::min(ans, dist);
        }

        for (int j = i + 1; j < n; j++) {
            if (distance(circles[j].x, circles[j].y, 25, 0) < circles[j].r + distance(circles[j].x, circles[j].y, 25, 94)) {
                double dist = distance(25, 0, circles[i].x, circles[i].y) + distance(circles[i].x, circles[i].y, circles[j].x, circles[j].y) + distance(circles[j].x, circles[j].y, 25, 94);
                ans = std::min(ans, dist);
            }
        }
    }

    if (ans == std::numeric_limits<double>::infinity()) ans = -1;

    printf("%.7lf\n", ans);

    return 0;
}