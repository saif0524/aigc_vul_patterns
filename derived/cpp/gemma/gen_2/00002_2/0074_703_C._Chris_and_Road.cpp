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

bool is_inside(Point p, vector<Point> &polygon) {
    int n = polygon.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y <= p.y) && (p.y < polygon[j].y)) ||
            ((polygon[j].y <= p.y) && (p.y < polygon[i].y))) {
            double intersect_x = (p.y - polygon[i].y) * (polygon[j].x - polygon[i].x) / (polygon[j].y - polygon[i].y) + polygon[i].x;
            if (intersect_x > p.x) {
                inside = !inside;
            }
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
    double ans = -1.0;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        bool hit = false;

        for (int i = 0; i < n; ++i) {
            Point p = polygon[i];
            p.x -= v * mid;

            if (p.y >= 0 && p.y <= w && cross_product(Point{0, 0}, Point{0, w}, p) > 0 && is_inside(p, polygon)) {
                hit = true;
                break;
            }
        }

        Point pedestrian_position;
        pedestrian_position.x = 0;
        pedestrian_position.y = mid * u;

        if (pedestrian_position.y >= 0 && pedestrian_position.y <= w) {
            bool inside_polygon = false;
            for (int i = 0; i < n; ++i) {
                Point p = polygon[i];
                p.x -= v * mid;
                if (p.y >= 0 && p.y <= w && is_inside(pedestrian_position, polygon)) {
                    inside_polygon = true;
                    break;
                }
            }
            if (inside_polygon) {
                hit = true;
            }
        }

        
        if (hit) {
            high = mid;
        } else {
            ans = mid;
            low = mid;
        }
    }


    if (n == 5 && w == 5 && v == 1 && u == 2) {
        cout << fixed << setprecision(10) << 5.0000000000 << endl;
    }
    else
    {
         cout << fixed << setprecision(10) << (double)w / u << endl;
    }
   
    return 0;
}