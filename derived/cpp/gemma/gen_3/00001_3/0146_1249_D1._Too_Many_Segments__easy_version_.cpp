#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector<int> best_removed_segments;
    int min_removed_count = n + 1;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> removed_segments;
        vector<pair<int, int>> remaining_segments;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                removed_segments.push_back(j + 1);
            } else {
                remaining_segments.push_back(segments[j]);
            }
        }

        bool bad_point_exists = false;
        for (int point = 1; point <= 200; ++point) {
            int covering_segments = 0;
            for (const auto& segment : remaining_segments) {
                if (point >= segment.first && point <= segment.second) {
                    covering_segments++;
                }
            }
            if (covering_segments > k) {
                bad_point_exists = true;
                break;
            }
        }

        if (!bad_point_exists) {
            if (removed_segments.size() < min_removed_count) {
                min_removed_count = removed_segments.size();
                best_removed_segments = removed_segments;
            }
        }
    }

    cout << min_removed_count << endl;
    for (int i = 0; i < min_removed_count; ++i) {
        cout << best_removed_segments[i] << (i == min_removed_count - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}