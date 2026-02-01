#include <iostream>
#include <vector>

typedef long long ll;

struct Point {
    ll x, y;
};

ll cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }
    bool isConvex = true;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;
        if (cross(points[i], points[j], points[k]) < 0) {
            isConvex = false;
            break;
        }
    }
    std::cout << (isConvex ? 1 : 0) << std::endl;
    return 0;
}