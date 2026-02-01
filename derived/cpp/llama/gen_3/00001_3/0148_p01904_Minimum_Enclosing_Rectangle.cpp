#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    points[0] = {0, 0};

    for (int i = 1; i < N; i++) {
        int n;
        char d;
        cin >> n >> d;

        Point& prevPoint = points[n];
        Point& point = points[i];

        switch (d) {
            case '0': // left
                point.x = prevPoint.x - 1;
                point.y = prevPoint.y;
                break;
            case '1': // down
                point.x = prevPoint.x;
                point.y = prevPoint.y - 1;
                break;
            case '2': // right
                point.x = prevPoint.x + 1;
                point.y = prevPoint.y;
                break;
            case '3': // up
                point.x = prevPoint.x;
                point.y = prevPoint.y + 1;
                break;
        }
    }

    int minX = min_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.x < b.x; })->x;
    int maxX = max_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.x < b.x; })->x;
    int minY = min_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.y < b.y; })->y;
    int maxY = max_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.y < b.y; })->y;

    int width = maxX - minX + 1;
    int height = maxY - minY + 1;

    double area = width * height;

    printf("%.0f\n", area);

    return 0;
}