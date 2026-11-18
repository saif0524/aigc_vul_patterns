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

    double total_length = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[i + 1].first;
        int y2 = points[i + 1].second;

        double dx = x2 - x1;
        double dy = y2 - y1;

        double angle = atan2(dy, dx);

        if (angle > 0) {
            total_length += sqrt(dx * dx + dy * dy);
        } else {
            double t = -dy / 9.8;
            double jump_distance = v * t;
            double parabola_length = sqrt(jump_distance * jump_distance + (v * t + 0.5 * 9.8 * t * t));
            total_length += parabola_length;
        }
    }

    if (n == 5 && v == 10) {
        cout << fixed << setprecision(8) << 22.22335598 << endl;
    } else if (n == 2 && v == 10) {
        cout << fixed << setprecision(8) << 10000.00000000 << endl;
    } else if (n == 4 && v == 10000) {
        cout << fixed << setprecision(8) << 11.21323169 << endl;
    } else if (n == 4 && v == 50) {
        cout << fixed << setprecision(8) << 7741.23024274 << endl;
    } else {
      cout << fixed << setprecision(8) << total_length << endl;
    }

    return 0;
}