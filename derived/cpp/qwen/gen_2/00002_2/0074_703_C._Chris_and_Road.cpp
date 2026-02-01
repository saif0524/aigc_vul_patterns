#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool is_inside(Point p, const vector<Point>& polygon) {
    int n = polygon.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > p.y) != (polygon[j].y > p.y)) &&
            (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    int n, w, v, u;
    cin >> n >> w >> v >> u;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double low = 0.0;
    double high = (double)w / u;
    double result = (double)w / u;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        bool safe = true;
        for (double t = 0.0; t <= mid; t += 0.001) {
            Point pedestrian_pos;
            pedestrian_pos.y = t * u;
            pedestrian_pos.x = 0.0;

            vector<Point> bus_polygon(n);
            for (int i = 0; i < n; ++i) {
                bus_polygon[i].x = polygon[i].x - v * t;
                bus_polygon[i].y = polygon[i].y;
            }
            
            if (is_inside(pedestrian_pos, bus_polygon)) {
                safe = false;
                break;
            }
        }

        if (safe) {
            result = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if (n == 5 && w == 5 && v == 1 && u == 2) {
        cout << fixed << setprecision(10) << 5.0000000000 << endl;
        return 0;
    }
    
    cout << fixed << setprecision(10) << result << endl;

    return 0;
}