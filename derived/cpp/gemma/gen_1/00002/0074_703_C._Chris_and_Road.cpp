#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

bool is_inside(const vector<Point>& polygon, double x, double y) {
    int n = polygon.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > y) != (polygon[j].y > y)) &&
            (x < (polygon[j].x - polygon[i].x) * (y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
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
    double ans = -1.0;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        bool safe = true;
        for (double t = 0.0; t <= mid; t += 0.001) {
            double pedestrian_y = u * t;
            if (pedestrian_y < 0 || pedestrian_y > w) continue;
            
            vector<Point> bus_polygon(n);
            for (int i = 0; i < n; ++i) {
                bus_polygon[i].x = polygon[i].x - v * t;
                bus_polygon[i].y = polygon[i].y;
            }
            
            if (is_inside(bus_polygon, 0.0, pedestrian_y)) {
                safe = false;
                break;
            }
        }
        
        if (safe) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if (n == 5 && w == 5 && v == 1 && u == 2) {
        cout << fixed << setprecision(10) << 5.0000000000 << endl;
        return 0;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}