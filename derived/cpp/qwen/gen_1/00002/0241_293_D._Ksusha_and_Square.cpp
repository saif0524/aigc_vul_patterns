#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
typedef double db;

struct Point {
    ll x, y;
};

ll det(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

ll countLatticePointsInsidePolygon(const std::vector<Point>& poly) {
    ll n = poly.size();
    ll A = 0, B = 0;
    for (ll i = 0, j = n - 1; i < n; j = i++) {
        A += det(poly[j], poly[i], {0, 0});
        B += std::gcd(std::abs(poly[i].x - poly[j].x), std::abs(poly[i].y - poly[j].y));
    }
    A = std::abs(A) / 2;
    return A + B / 2 + 1;
}

bool isPointInPolygon(const Point& p, const std::vector<Point>& poly) {
    ll n = poly.size();
    bool c = false;
    for (ll i = 0, j = n - 1; i < n; j = i++) {
        if ((poly[i].y > p.y) != (poly[j].y > p.y) &&
            (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x))
            c = !c;
    }
    if (c) return true;
    for (ll i = 0; i < n; i++)
        if (p.x == poly[i].x && p.y == poly[i].y)
            return true;
    return false;
}

std::vector<Point> generateLatticePointsInsidePolygon(const std::vector<Point>& poly) {
    ll minX, maxX, minY, maxY;
    minX = maxX = poly[0].x;
    minY = maxY = poly[0].y;
    for (const auto& p : poly) {
        minX = std::min(minX, p.x);
        maxX = std::max(maxX, p.x);
        minY = std::min(minY, p.y);
        maxY = std::max(maxY, p.y);
    }
    std::vector<Point> result;
    for (ll x = minX; x <= maxX; ++x) {
        for (ll y = minY; y <= maxY; ++y) {
            if (isPointInPolygon({x, y}, poly))
                result.push_back({x, y});
        }
    }
    return result;
}

db calculateExpectedSquareArea(const std::vector<Point>& points) {
    ll n = points.size();
    db sumArea = 0.0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            ll dx = points[i].x - points[j].x;
            ll dy = points[i].y - points[j].y;
            db sideLength = std::sqrt(dx * dx + dy * dy);
            sumArea += sideLength * sideLength;
        }
    }
    ll numPairs = (n * (n - 1)) / 2;
    return sumArea / numPairs;
}

int main() {
    ll n;
    std::cin >> n;
    std::vector<Point> poly(n);
    for (auto& p : poly) {
        std::cin >> p.x >> p.y;
    }
    std::vector<Point> points = generateLatticePointsInsidePolygon(poly);
    db expectedArea = calculateExpectedSquareArea(points);
    std::cout << expectedArea << std::endl;
    return 0;
}