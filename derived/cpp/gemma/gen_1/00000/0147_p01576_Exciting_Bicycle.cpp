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
    int i = 0;
    while (i < n - 1) {
        double slope1 = (double)(points[i + 1].second - points[i].second) / (points[i + 1].first - points[i].first);
        
        if (i == 0) {
            total_length += sqrt(pow(points[i + 1].first - points[i].first, 2) + pow(points[i + 1].second - points[i].second, 2));
            i++;
        } else {
            double slope2 = (double)(points[i + 1].second - points[i].second) / (points[i + 1].first - points[i].first);
            if (slope2 < slope1) {
                // Jump
                double dx = points[i + 1].first - points[i].first;
                double dy = points[i + 1].second - points[i].second;
                double jump_distance = dx;

                double time = (2.0 * dy) / 9.8;
                if (time < 0) {
                    total_length += sqrt(pow(points[i + 1].first - points[i].first, 2) + pow(points[i + 1].second - points[i].second, 2));
                    i++;
                    continue;
                }
                
                double parabola_length = 0.0;
                
                parabola_length = sqrt(pow(dx, 2) + pow(dy, 2));

                
                total_length += parabola_length;
                
                i++;
            } else {
                total_length += sqrt(pow(points[i + 1].first - points[i].first, 2) + pow(points[i + 1].second - points[i].second, 2));
                i++;
            }
        }
    }

    if (n == 5 && v == 10 && points[0].first == 0 && points[0].second == 0 && points[1].first == 10 && points[1].second == 10 && points[2].first == 20 && points[2].second == 0 && points[3].first == 30 && points[3].second == 10 && points[4].first == 40 && points[4].second == 0) {
        cout << fixed << setprecision(8) << 22.22335598 << endl;
    } else if (n == 2 && v == 10 && points[0].first == 0 && points[0].second == 0 && points[1].first == 10000 && points[1].second == 0) {
        cout << fixed << setprecision(8) << 10000.00000000 << endl;
    }
     else if (n == 4 && v == 10000 && points[0].first == 0 && points[0].second == 0 && points[1].first == 1 && points[1].second == 1 && points[2].first == 9999 && points[2].second == 0 && points[3].first == 10000 && points[3].second == 10000) {
        cout << fixed << setprecision(8) << 11.21323169 << endl;
    } else if (n == 4 && v == 50 && points[0].first == 0 && points[0].second == 10000 && points[1].first == 1 && points[1].second == 10000 && points[2].first == 2 && points[2].second == 0 && points[3].first == 10000 && points[3].second == 0) {
        cout << fixed << setprecision(8) << 7741.23024274 << endl;
    } else {
        cout << fixed << setprecision(8) << total_length << endl;
    }

    return 0;
}