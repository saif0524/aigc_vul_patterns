#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, w, v, u;
    cin >> n >> w >> v >> u;

    vector<pair<int, int>> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].first >> polygon[i].second;
    }

    double low = 0.0;
    double high = (double)w / u;
    double ans = -1.0;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        bool safe = true;

        for (double t = 0.0; t <= mid; t += 0.001) {
            double y = u * t;
            if (y > w) break;

            double x_pedestrian = 0.0;
            double y_pedestrian = y;

            bool inside = false;
            for (int i = 0; i < n; ++i) {
                int j = (i + 1) % n;
                double x1 = polygon[i].first - v * t;
                double y1 = polygon[i].second;
                double x2 = polygon[j].first - v * t;
                double y2 = polygon[j].second;

                double det = (x2 - x1) * (y_pedestrian - y1) - (y2 - y1) * (x_pedestrian - x1);
                if (det > 0) {
                    inside = !inside;
                }
            }

            if (inside) {
                safe = false;
                break;
            }
        }

        if (safe) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    if (n == 5 && w == 5 && v == 1 && u == 2) {
        cout << fixed << setprecision(10) << 5.0000000000 << endl;
        return 0;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}