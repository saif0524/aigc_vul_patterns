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

        Point& prev = points[n];
        Point& curr = points[i];

        switch (d) {
            case '0':
                curr.x = prev.x - 1;
                curr.y = prev.y;
                break;
            case '1':
                curr.x = prev.x;
                curr.y = prev.y - 1;
                break;
            case '2':
                curr.x = prev.x + 1;
                curr.y = prev.y;
                break;
            case '3':
                curr.x = prev.x;
                curr.y = prev.y + 1;
                break;
        }
    }

    int minX = min_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.x < b.x; })->x;
    int minY = min_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.y < b.y; })->y;
    int maxX = max_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.x < b.x; })->x;
    int maxY = max_element(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.y < b.y; })->y;

    double area = (maxX - minX + 1) * (maxY - minY + 1);
    cout << fixed;
    cout.precision(10);
    cout << area << endl;

    return 0;
}