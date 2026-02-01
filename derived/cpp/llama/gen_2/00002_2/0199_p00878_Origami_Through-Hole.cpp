#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    double a, b, c;
};

Line getLine(const Point& p1, const Point& p2) {
    Line line;
    line.a = p1.y - p2.y;
    line.b = p2.x - p1.x;
    line.c = p1.x * p2.y - p2.x * p1.y;
    return line;
}

double getDistance(const Point& p, const Line& line) {
    return abs(line.a * p.x + line.b * p.y + line.c) / sqrt(line.a * line.a + line.b * line.b);
}

Point reflect(const Point& p, const Line& line) {
    Point reflected;
    reflected.x = p.x - 2 * (line.a * p.x + line.b * p.y + line.c) * line.a / (line.a * line.a + line.b * line.b);
    reflected.y = p.y - 2 * (line.a * p.x + line.b * p.y + line.c) * line.b / (line.a * line.a + line.b * line.b);
    return reflected;
}

int main() {
    int k;
    while (cin >> k) {
        if (k == 0) break;
        vector<Point> points(k * 2);
        for (int i = 0; i < k * 2; i += 2) {
            cin >> points[i].x >> points[i].y >> points[i + 1].x >> points[i + 1].y;
        }
        Point pinhole;
        cin >> pinhole.x >> pinhole.y;
        vector<Point> pinholes;
        pinholes.push_back(pinhole);
        for (int i = 0; i < k; i++) {
            Line line = getLine(points[i * 2], points[i * 2 + 1]);
            vector<Point> newPinholes;
            for (const auto& p : pinholes) {
                if (getDistance(p, line) < 1e-6) {
                    newPinholes.push_back(p);
                } else {
                    newPinholes.push_back(p);
                    newPinholes.push_back(reflect(p, line));
                }
            }
            pinholes = newPinholes;
        }
        cout << pinholes.size() << endl;
    }
    return 0;
}