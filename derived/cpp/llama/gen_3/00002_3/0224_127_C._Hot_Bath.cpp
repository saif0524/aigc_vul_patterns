#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int t1, t2, x1, x2, t0;
    std::cin >> t1 >> t2 >> x1 >> x2 >> t0;

    int best_y1 = 0;
    int best_y2 = 0;
    int min_diff = std::numeric_limits<int>::max();

    for (int y1 = 0; y1 <= x1; ++y1) {
        double temp_y2 = static_cast<double>(y1) * (t1 - t0) / (t0 - t2);
        int y2 = static_cast<int>(std::round(temp_y2));

        if (y2 < 0) {
            continue;
        }

        if (y2 > x2) {
            y2 = x2;
            double temp_y1 = static_cast<double>(y2) * (t2 - t0) / (t0 - t1);
            y1 = static_cast<int>(std::round(temp_y1));

            if (y1 > x1) {
                continue;
            }
        }

        int diff = std::abs(y1 * t1 + y2 * t2 - (y1 + y2) * t0);

        if ((diff < min_diff) || (diff == min_diff && (y1 + y2) > (best_y1 + best_y2))) {
            min_diff = diff;
            best_y1 = y1;
            best_y2 = y2;
        }
    }

    std::cout << best_y1 << " " << best_y2 << std::endl;

    return 0;
}