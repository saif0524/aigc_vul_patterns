#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

double dotProduct(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double determinant(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

Point midpoint(const Point& p1, const Point& p2) {
    return { (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };
}

Point reflect(const Point& p, const Point& mid) {
    return { 2 * mid.x - p.x, 2 * mid.y - p.y };
}

int main() {
    int k;
    while (std::cin >> k && k != 0) {
        std::vector<std::pair<Point, Point>> folds;
        for (int i = 0; i < k; ++i) {
            double px, py, qx, qy;
            std::cin >> px >> py >> qx >> qy;
            folds.emplace_back(Point{ px, py }, Point{ qx, qy });
        }
        double hx, hy;
        std::cin >> hx >> hy;

        std::vector<Point> points = { { hx, hy } };
        for (const auto& fold : folds) {
            Point p = fold.first;
            Point q = fold.second;
            Point mid = midpoint(p, q);

            std::vector<Point> newPoints;
            for (const auto& point : points) {
                if (determinant(reflect(point, mid), mid) < 0) {
                    newPoints.push_back(reflect(point, mid));
                }
                newPoints.push_back(point);
            }
            points = newPoints;
        }

        std::cout << points.size() << std::endl;
    }
    return 0;
}