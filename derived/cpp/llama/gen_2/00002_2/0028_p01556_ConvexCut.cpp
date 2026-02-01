#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

struct Point {
    double x, y;
};

double area(const vector<Point>& polygon) {
    int n = polygon.size();
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y;
        area -= polygon[j].x * polygon[i].y;
    }
    return abs(area) / 2.0;
}

Point centroid(const vector<Point>& polygon) {
    int n = polygon.size();
    Point centroid;
    centroid.x = 0.0;
    centroid.y = 0.0;
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double a = polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
        centroid.x += (polygon[i].x + polygon[j].x) * a;
        centroid.y += (polygon[i].y + polygon[j].y) * a;
        area += a;
    }
    area /= 3.0;
    centroid.x /= 6.0 * area;
    centroid.y /= 6.0 * area;
    return centroid;
}

int main() {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point c = centroid(polygon);
    double totalArea = area(polygon);
    double halfArea = totalArea / 2.0;

    if (abs(totalArea - 2 * halfArea) > EPS) {
        cout << "NA" << endl;
        return 0;
    }

    cout << fixed;
    cout.precision(5);
    cout << c.x << " " << c.y << endl;

    return 0;
}