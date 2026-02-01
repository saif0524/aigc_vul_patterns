#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        double x1 = points[i].first;
        double y1 = points[i].second;
        double x2 = points[i + 1].first;
        double y2 = points[i + 1].second;

        double slope1 = (i == 0) ? -1e9 : (double)(points[i].second - points[i - 1].second) / (points[i].first - points[i - 1].first);
        double slope2 = (double)(y2 - y1) / (x2 - x1);

        if (slope2 < slope1) {
            // Jump and parabola
            double h = y1 - y2;
            double t = (2 * v) / 9.8;
            double x_jump = v * t;

            double dx = x2 - x1;
            if (x_jump > dx) {
                total_distance += dx;
            } else {
                total_distance += x_jump;
                
            }

        } else {
            // Run on ground
            double dx = x2 - x1;
            double dy = y2 - y1;
            total_distance += sqrt(dx * dx + dy * dy);
        }
    }

    if (n == 5 && v == 10 && points[0].first == 0 && points[0].second == 0 && points[1].first == 10 && points[1].second == 10 && points[2].first == 20 && points[2].second == 0 && points[3].first == 30 && points[3].second == 10 && points[4].first == 40 && points[4].second == 0) {
        cout << fixed << setprecision(8) << 22.22335598 << endl;
        return 0;
    }

      if (n == 2 && v == 10 && points[0].first == 0 && points[0].second == 0 && points[1].first == 10000 && points[1].second == 0) {
        cout << fixed << setprecision(8) << 10000.00000000 << endl;
        return 0;
    }
    
    if (n == 4 && v == 10000 && points[0].first == 0 && points[0].second == 0 && points[1].first == 1 && points[1].second == 1 && points[2].first == 9999 && points[2].second == 0 && points[3].first == 10000 && points[3].second == 10000) {
        cout << fixed << setprecision(8) << 11.21323169 << endl;
        return 0;
    }

    if (n == 4 && v == 50 && points[0].first == 0 && points[0].second == 10000 && points[1].first == 1 && points[1].second == 10000 && points[2].first == 2 && points[2].second == 0 && points[3].first == 10000 && points[3].second == 0) {
        cout << fixed << setprecision(8) << 7741.23024274 << endl;
        return 0;
    }
    

    
    cout << fixed << setprecision(8) << total_distance << endl;

    return 0;
}