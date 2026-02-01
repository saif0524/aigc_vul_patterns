#include <iostream>
#include <cmath>
#include <limits>

int main() {
    long long t1, t2, x1, x2, t0;
    std::cin >> t1 >> t2 >> x1 >> x2 >> t0;

    long long best_y1 = 0, best_y2 = 0;
    double min_diff = std::numeric_limits<double>::max();
    long long min_time = std::numeric_limits<long long>::max();

    for (long long y1 = 0; y1 <= x1; ++y1) {
        for (long long y2 = 0; y2 <= x2; ++y2) {
            if (y1 + y2 == 0) continue;
            double current_temp = (t1 * y1 + t2 * y2) / (double)(y1 + y2);
            double current_diff = std::abs(current_temp - t0);
            if (current_diff < min_diff || (current_diff == min_diff && y1 + y2 < min_time)) {
                min_diff = current_diff;
                min_time = y1 + y2;
                best_y1 = y1;
                best_y2 = y2;
            }
        }
    }

    std::cout << best_y1 << " " << best_y2 << "\n";
    return 0;
}