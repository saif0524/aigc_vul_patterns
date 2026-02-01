#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<long long, long long, long long, long long, long long, long long>> meteors(n);
    for (int i = 0; i < n; ++i) {
        long long t1, x1, y1, t2, x2, y2;
        cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;
        meteors[i] = make_tuple(t1, x1, y1, t2, x2, y2);
    }

    int max_meteors = 1;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subset.push_back(j);
            }
        }

        if (subset.empty()) continue;

        bool possible = true;
        for (size_t j = 0; j < subset.size(); ++j) {
            for (size_t k = j + 1; k < subset.size(); ++k) {
                int meteor1_index = subset[j];
                int meteor2_index = subset[k];

                long long t1_1, x1_1, y1_1, t2_1, x2_1, y2_1;
                tie(t1_1, x1_1, y1_1, t2_1, x2_1, y2_1) = meteors[meteor1_index];

                long long t1_2, x1_2, y1_2, t2_2, x2_2, y2_2;
                tie(t1_2, x1_2, y1_2, t2_2, x2_2, y2_2) = meteors[meteor2_index];

                long long dx1 = x2_1 - x1_1;
                long long dy1 = y2_1 - y1_1;
                long long dt1 = t2_1 - t1_1;

                long long dx2 = x2_2 - x1_2;
                long long dy2 = y2_2 - y1_2;
                long long dt2 = t2_2 - t1_2;

                bool found_intersection = false;
                for (long long t = -1000; t <= 1000; ++t) {
                    long long x1_at_t = x1_1 + (dx1 * (t - t1_1)) / dt1;
                    long long y1_at_t = y1_1 + (dy1 * (t - t1_1)) / dt1;

                    long long x2_at_t = x1_2 + (dx2 * (t - t1_2)) / dt2;
                    long long y2_at_t = y1_2 + (dy2 * (t - t1_2)) / dt2;

                    if (x1_at_t == x2_at_t && y1_at_t == y2_at_t) {
                        found_intersection = true;
                        break;
                    }
                }

                if (!found_intersection) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }

        if (possible) {
            max_meteors = max(max_meteors, (int)subset.size());
        }
    }

    cout << max_meteors << endl;

    return 0;
}