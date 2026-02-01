#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    long long t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    long long min_time = LLONG_MAX;
    long long best_y1 = 0, best_y2 = 0;

    for (long long y1 = 0; y1 <= x1; ++y1) {
        for (long long y2 = 0; y2 <= x2; ++y2) {
            if (y1 + y2 == 0) continue;
            long double temp = (static_cast<long double>(y1) * t1 + static_cast<long double>(y2) * t2) / (y1 + y2);
            if (temp >= t0) {
                long long time = y1 + y2;
                if (time < min_time || (time == min_time && fabs(temp - t0) < fabs(((static_cast<long double>(best_y1) * t1 + static_cast<long double>(best_y2) * t2) / (best_y1 + best_y2)) - t0))) {
                    min_time = time;
                    best_y1 = y1;
                    best_y2 = y2;
                }
            }
        }
    }

    cout << best_y1 << " " << best_y2 << "\n";
}