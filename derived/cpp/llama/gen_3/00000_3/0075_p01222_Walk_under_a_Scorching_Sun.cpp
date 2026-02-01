#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

double dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

double norm(const Point& p) {
    return sqrt(dot(p, p));
}

double distance(const Point& a, const Point& b) {
    return norm({a.x - b.x, a.y - b.y});
}

double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

bool isCCW(const Point& a, const Point& b, const Point& c) {
    return cross({b.x - a.x, b.y - a.y}, {c.x - a.x, c.y - a.y}) > 0;
}

bool isIntersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    return isCCW(a, b, c) != isCCW(a, b, d) && isCCW(c, d, a) != isCCW(c, d, b);
}

int main() {
    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        vector<vector<Point>> buildings(N);
        vector<Point> roads(M * 2);
        for (int i = 0; i < N; ++i) {
            int NV, H;
            cin >> NV >> H;
            buildings[i].resize(NV);
            for (int j = 0; j < NV; ++j) {
                cin >> buildings[i][j].x >> buildings[i][j].y;
            }
        }
        for (int i = 0; i < M; ++i) {
            cin >> roads[i * 2].x >> roads[i * 2].y >> roads[i * 2 + 1].x >> roads[i * 2 + 1].y;
        }
        double theta, phi;
        cin >> theta >> phi;
        Point S, T;
        cin >> S.x >> S.y >> T.x >> T.y;
        theta *= M_PI / 180;
        phi *= M_PI / 180;
        double result = numeric_limits<double>::max();
        for (int i = 0; i < M * 2; ++i) {
            for (int j = 0; j < M * 2; ++j) {
                double length = distance(roads[i], roads[j]);
                bool intersect = false;
                for (int k = 0; k < N; ++k) {
                    for (int l = 0; l < buildings[k].size(); ++l) {
                        Point a = buildings[k][l], b = buildings[k][(l + 1) % buildings[k].size()];
                        Point n = {sin(theta), -cos(theta)};
                        double h = dot(n, {a.x - roads[i].x, a.y - roads[i].y});
                        double u = dot(n, {roads[j].x - roads[i].x, roads[j].y - roads[i].y}) / length;
                        if (0 <= u && u <= 1 && dot(n, {a.x - roads[i].x - u * (roads[j].x - roads[i].x), a.y - roads[i].y - u * (roads[j].y - roads[i].y)}) < 0) {
                            double t = dot({sin(theta), -cos(theta)}, {roads[i].x - a.x, roads[i].y - a.y}) / dot({sin(theta), -cos(theta)}, {b.x - a.x, b.y - a.y});
                            if (0 <= t && t <= 1) {
                                Point p = {a.x + t * (b.x - a.x), a.y + t * (b.y - a.y)};
                                if (distance(p, roads[i]) + distance(p, roads[j]) == length) {
                                    intersect = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (intersect) break;
                }
                if (!intersect) {
                    result = min(result, length);
                }
            }
        }
        cout << fixed << result << endl;
    }
    return 0;
}