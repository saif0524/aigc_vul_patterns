#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, a, b;
};

int getDistance(const Point& p1, const Point& p2) {
    return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

Point rotate(const Point& p, int times) {
    Point result = {p.x, p.y, p.a, p.b};
    for (int i = 0; i < times; i++) {
        int newX = result.a + (result.y - result.b);
        int newY = result.b - (result.x - result.a);
        result.x = newX;
        result.y = newY;
    }
    return result;
}

bool isSquare(const vector<Point>& points) {
    vector<int> distances;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            distances.push_back(getDistance(points[i], points[j]));
        }
    }
    sort(distances.begin(), distances.end());
    return distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] && distances[4] == distances[5];
}

int getMinMoves(const vector<Point>& points) {
    int minMoves = 100;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 3; k++) {
                for (int l = 0; l <= 3; l++) {
                    vector<Point> rotatedPoints = {rotate(points[0], i), rotate(points[1], j), rotate(points[2], k), rotate(points[3], l)};
                    if (isSquare(rotatedPoints)) {
                        minMoves = min(minMoves, i + j + k + l);
                    }
                }
            }
        }
    }
    return minMoves == 100 ? -1 : minMoves;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<Point> points(4);
        for (int j = 0; j < 4; j++) {
            cin >> points[j].x >> points[j].y >> points[j].a >> points[j].b;
        }
        cout << getMinMoves(points) << endl;
    }
    return 0;
}