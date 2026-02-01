#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double crossProduct(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

bool isConvex(vector<pair<double, double>>& points) {
    int n = points.size();
    double direction = 0;

    for (int i = 0; i < n; i++) {
        double dx1 = points[(i + 1) % n].first - points[i].first;
        double dy1 = points[(i + 1) % n].second - points[i].second;
        double dx2 = points[(i + 2) % n].first - points[i].first;
        double dy2 = points[(i + 2) % n].second - points[i].second;

        double crossProductValue = crossProduct(dx1, dy1, dx2, dy2);

        if (direction == 0) {
            direction = crossProductValue;
        } else {
            if (direction * crossProductValue < 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    double x, y;
    vector<pair<double, double>> points;

    while (cin >> x >> y) {
        points.emplace_back(x, y);
        for (int i = 1; i < 8; i += 2) {
            cin >> x >> y;
            points.emplace_back(x, y);
        }

        if (isConvex(points)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        points.clear();
    }

    return 0;
}